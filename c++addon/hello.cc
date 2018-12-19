// hello.cc
#include <node.h>
#include <iostream>

namespace demo {

using namespace v8;
using std::cout;
using std::endl;

Local<Array> NewPointArray(int x, int y, int z) {
  v8::Isolate* isolate = v8::Isolate::GetCurrent();
  v8::EscapableHandleScope handle_scope(isolate);
  Local<Array> array = Array::New(isolate, 3);

  array->Set(0, v8::Integer::New(isolate, x));
  array->Set(1, v8::Integer::New(isolate, y));
  array->Set(2, v8::Integer::New(isolate, z));

  return handle_scope.Escape(array);
}

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<String> str = String::NewFromUtf8(isolate, "Hello World");
  Local<Number> num = Number::New(isolate, 10000);
  // args.GetReturnValue().Set(NewPointArray(1, 2, 3));
  args.GetReturnValue().Set(num->ToString());
  // args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}


void Callback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "Hello world!")};
  cb->Call(Null(isolate), argc, argv);
}

// void init(Local<Object> exports) {
//   cout << "hello world" << endl;
//   NODE_SET_METHOD(exports, "hello", Method);
//   NODE_SET_METHOD(exports, "call", Callback);
// }

void Console(const FunctionCallbackInfo<Value> &args) {
  Isolate* isolate = args.GetIsolate();
  Local<String> string = String::NewFromUtf8(isolate, "This is a Console Function!");
  args.GetReturnValue().Set(string);
}

void init(Local<Object> exports) {
  v8::Isolate* isolate = v8::Isolate::GetCurrent();
  v8::HandleScope handle_scope(isolate);
  v8::Local<v8::FunctionTemplate> t = v8::FunctionTemplate::New(isolate, Console);
  v8::Local<v8::Function> fn = t->GetFunction();
  v8::Local<v8::String> fn_name = v8::String::NewFromUtf8(isolate, "hello");
  // fn->SetName(fn_name);
  exports->Set(fn_name, fn);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo