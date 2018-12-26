#include <stdio.h>
#include <uv.h>

int64_t counter = 0;

void waiting_for_a_while(uv_idle_t* handle) {
    counter++;
    printf("%lld\n", counter);
    if (counter >= 10e6) {
        uv_idle_stop(handle);
    }
}

int main(int argc, char const *argv[])
{
    uv_idle_t idler;

    uv_idle_init(uv_default_loop(), &idler);
    uv_idle_start(&idler, waiting_for_a_while);

    printf("Idling...\n");
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_loop_close(uv_default_loop());
    return 0;
}