#include <node.h>

using namespace v8;

void Constructor(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.This()->Set(String::NewFromUtf8(isolate, "value"), 
        Number::New(isolate, 233)
    );
    args.GetReturnValue().Set(args.This());
}

void ClassGet(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    return args.GetReturnValue().Set(args.This()->Get(String::NewFromUtf8(isolate, "value")));
}   

void ClassSet(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.This()->Set(String::NewFromUtf8(isolate, "value"), Number::New(isolate, 2333333));
}

void Init(Local<Object> exports) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, Constructor);
    // tpl->SetClassName(String::NewFromUtf8(isolate, "TestClass"));
    Local<ObjectTemplate> proto = tpl->PrototypeTemplate();
    proto->Set(String::NewFromUtf8(isolate, "get"), FunctionTemplate::New(isolate, ClassGet));
    proto->Set(String::NewFromUtf8(isolate, "set"), FunctionTemplate::New(isolate, ClassSet));
    exports->Set(String::NewFromUtf8(isolate, "TestClass"), tpl->GetFunction());
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)