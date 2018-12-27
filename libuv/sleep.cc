#include <node.h>
#include <nan.h>
#include <vector>
#include <unistd.h>
#include <iostream>

using namespace v8;

struct ThreadArg {
    std::vector<uint32_t>* vec;
    uint32_t num;
};

void Sleep(void* _)
{
    ThreadArg* arg = (ThreadArg*)_;
    usleep(arg->num * 100 * 10000);
    arg->vec->push_back(arg->num);

    delete arg;
}

NAN_METHOD(Sort)
{
    if(info.Length() < 1 || !info[0]->IsArray())
    {
        return Nan::ThrowError("Wrong argument");
    }

    Local<Array> array = info[0].As<Array>();

    std::vector<uint32_t> orig;

    for(uint32_t i = 0; i < array->Length(); i++)
    {
        if(!Nan::Get(array, i).ToLocalChecked()->IsUint32())
        {
            return Nan::ThrowTypeError("Elements should be unsigned int.");
        }

        orig.push_back(Nan::To<uint32_t>(Nan::Get(array, i).ToLocalChecked()).FromJust());
    }

    std::vector<uint32_t> vec;
    std::vector<uv_thread_t> handles(array->Length());
    for(uint32_t i = 0; i < array->Length(); i++)
    {
        ThreadArg* arg = new ThreadArg();
        arg->vec = &vec;
        arg->num = orig[i];
        uv_thread_create(&handles[i], Sleep, arg);
    }

    for(uint32_t i = 0; i < handles.size(); i++)
    {
        uv_thread_join(&handles[i]);
    }
    std::cout << "end" << std::endl;
    Local<Array> ret = Nan::New<Array>();
    for(uint32_t i = 0; i < array->Length(); i++)
    {
        Local<Value> v = Nan::New(vec[i]);
        Nan::Set(ret, i, v);
    }

    info.GetReturnValue().Set(ret);
}

NAN_MODULE_INIT(Init)
{
    // Nan::Set(target, Nan::New<String>("echo").ToLocalChecked(),
    //     Nan::GetFunction(Nan::New<FunctionTemplate>(Echo)).ToLocalChecked());
    Nan::Export(target, "sort", Sort);
}

NODE_MODULE(sort, Init)