#ifndef MYOBJECT_H
#define MYOBJECT_H
#include <node.h>
#include <node/node_object_wrap.h>

namespace demo {
using namespace v8;
    class MyObject: public node::ObjectWrap {
        public:
            static void Init(Local<Object> exports);
        
        private:
            explicit MyObject(double value = 0);
            ~MyObject();

            static void New(const FunctionCallbackInfo<Value>& args);
            static void PlusOne(const FunctionCallbackInfo<Value>& args);
            static Persistent<Function> constructor;
            double value_;
    };
}

#endif