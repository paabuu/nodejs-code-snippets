#include <node.h>

using namespace v8;

void Func(const FunctionCallbackInfo<Value>& args) {
    args.GetReturnValue().Set(455);
}

void Init(Local<Object> exports) {
    Isolate* isolate = Isolate::GetCurrent();
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate);
    Local<ObjectTemplate> obj = ObjectTemplate::New(isolate, tpl);
    obj->SetCallAsFunctionHandler(Func);
    obj->Set(String::NewFromUtf8(isolate, "value"), Number::New(isolate, 23333));
    exports->Set(String::NewFromUtf8(isolate, "obj"), obj->NewInstance());
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)