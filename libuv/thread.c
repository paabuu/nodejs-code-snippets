#include <uv.h>
#include <unistd.h>

void _sleep(void* sleep_time) {
    printf("sleep!");
    sleep(*(int*)sleep_time);
}

int main(int argc, char const *argv[])
{
    int sleep_time = 1;
    uv_thread_t id;
    uv_thread_create(&id, _sleep, &sleep_time);
    uv_thread_join(&id);
    printf("awake!");
    return 0;
}
