#include <node.h>

using namespace v8;

int x = 0;

void Getter1(Local<String> property, const PropertyCallbackInfo<Value> & args) {
    args.GetReturnValue().Set(x);
}

void Setter1(Local<String> property, Local<Value> value, const PropertyCallbackInfo<void> & args) {
    x = value->Int32Value();
}

void Init(Local<Object> exports, Local<Object> module) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    Local<ObjectTemplate> obj = ObjectTemplate::New(isolate);
    obj->SetAccessor(String::NewFromUtf8(isolate, "var1"), Getter1, Setter1);
    module->Set(String::NewFromUtf8(isolate, "exports"), obj->NewInstance());
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init);