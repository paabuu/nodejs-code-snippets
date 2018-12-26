#include <stdio.h>
#include <nan.h>

unsigned int idle_times = 0;
uv_idle_t* idle = 0;

void test_idle(uv_idle_t* handle) {
    printf("还剩%d次空转!\n", idle_times);
    idle_times--;

    if (idle_times == 0)
    {
        printf("空转结束!\n");
        idle = 0;
        uv_idle_stop(handle);
        delete handle;
    }
}

NAN_METHOD(StartIdle)
{
    printf("start idle\n");
    idle_times = Nan::To<unsigned int>(info[0]).FromJust();

    idle = new uv_idle_t();

    uv_idle_init(uv_default_loop(), idle);

    uv_idle_start(idle, test_idle);
}

NAN_MODULE_INIT(Init)
{
    // Nan::Set(target, Nan::New<String>("echo").ToLocalChecked(),
    //     Nan::GetFunction(Nan::New<FunctionTemplate>(Echo)).ToLocalChecked());
    Nan::Export(target, "startIdle", StartIdle);
}

NODE_MODULE(startIdle, Init)