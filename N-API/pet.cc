#include <nan.h>

using namespace v8;

NAN_METHOD(Pet)
{
    Local<Object> self = info.This();

    Nan::Set(
        self,
        Nan::New("name").ToLocalChecked(),
        Nan::New("Unknown").ToLocalChecked()
    );

    Nan::Set(
        self,
        Nan::New("type").ToLocalChecked(),
        Nan::New("animal").ToLocalChecked()
    );

    info.GetReturnValue().Set(self);
}

NAN_METHOD(SetName)
{
    Nan::Set(info.This(), Nan::New("name").ToLocalChecked(), info[0]);
}

NAN_METHOD(Summary)
{
    Local<Object> self = info.This();
    char temp[512];
    Nan::Utf8String type(
        Nan::Get(self, Nan::New("type").ToLocalChecked()).ToLocalChecked()->ToString());
    Nan::Utf8String name(
        Nan::Get(self, Nan::New("name").ToLocalChecked()).ToLocalChecked()->ToString());

    snprintf(temp, 511, "%s is a/an %s", *name, *type);
    info.GetReturnValue().Set(Nan::New(temp).ToLocalChecked());
}

NAN_MODULE_INIT(Init) 
{
    Local<FunctionTemplate> pet = Nan::New<FunctionTemplate>(Pet);

    Nan::SetPrototypeMethod(pet, "setName", SetName);
    Nan::SetPrototypeMethod(pet, "summary", Summary);

    Local<Function> pet_cons = pet->GetFunction();

    Nan::Set(target, Nan::New("pet").ToLocalChecked(), pet_cons);
}

NODE_MODULE(pet, Init)