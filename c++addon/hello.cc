// hello.cc
#include <node.h>
#include <iostream>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Function;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;
using v8::Null;
using std::cout;
using std::endl;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<String> str = String::NewFromUtf8(isolate, "Hello World");
  Local<Number> num = Number::New(isolate, 10000);
  args.GetReturnValue().Set(Local<String>::Cast(num));
  // args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void Callback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "Hello world!")};
  cb->Call(Null(isolate), argc, argv);
}

void init(Local<Object> exports) {
  cout << "hello world" << endl;
  NODE_SET_METHOD(exports, "hello", Method);
  NODE_SET_METHOD(exports, "call", Callback);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo