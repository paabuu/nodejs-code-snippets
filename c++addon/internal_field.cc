#include <node.h>
#include <iostream>

using namespace v8;

void GetInfo(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Object> self = args.Holder();
    Local<String> info = Local<String>::Cast(self->GetInternalField(0));
    args.GetReturnValue().Set(info);
}

void Init(Local<Object> exports, Local<Object> module) {
    Isolate* isolate = Isolate::GetCurrent();
    Local<ObjectTemplate> obj_tpl = ObjectTemplate::New(isolate);
    obj_tpl->SetInternalFieldCount(1);
    Local<Object> obj = obj_tpl->NewInstance();
    obj->SetInternalField(0, String::NewFromUtf8(isolate, "I am a internal field!"));
    obj->Set(String::NewFromUtf8(isolate, "name"), String::NewFromUtf8(isolate, "wenjie"));

    Local<FunctionTemplate> func = FunctionTemplate::New(isolate, GetInfo);

    obj->Set(String::NewFromUtf8(isolate, "getInfo"), func->GetFunction());
    module->Set(String::NewFromUtf8(isolate, "exports"), obj);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)