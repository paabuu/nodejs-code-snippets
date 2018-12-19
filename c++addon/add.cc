#include <node.h>

using namespace v8;

void Add(const FunctionCallbackInfo<Value> & args) {
    Isolate* isolate = args.GetIsolate();
    if (args.Length() < 2) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "参数数量错误！")));
        return;
    }

    if(!args[0]->IsNumber() || !args[1]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "参数类型错误！")));
        return;
    }
    double value = args[0]->NumberValue() + args[1]->NumberValue();
    Local<Number> sum = Number::New(isolate, value);
    args.GetReturnValue().Set(sum);
}

void Init(Local<Object> exports, Local<Object> module) {
    NODE_SET_METHOD(module, "exports", Add);
}   

NODE_MODULE(MODE_GYP_MODULE_NAME, Init)