#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct
{
    char *hoten;
    int sdt;
    int namsinh;
    char *quequan;
}human_t;

pthread_t  thread_id1, thread_id2;

void *thr_handle(void *args)
{
    human_t *data = (human_t *)args;
    pthread_t thr_id = pthread_self();
    if(pthread_equal(thr_id, thread_id1))
    {
        printf("I'm thread 1\n");
    }
    else
    {
        printf("Ho va ten: %s\n", data->hoten);
        printf("SDT: %d\n", data->sdt);
        printf("Nam sinh: %d\n", data->namsinh);
        printf("Que quan: %s\n", data->quequan);
    }

}

// void *thr2_handle(void *args)
// {

// }

int main(int argc, char const *argv[])
{
    int fd;
    int ret;
    human_t my_data;
    my_data.hoten = "abc";
    my_data.quequan = "TB";
    my_data.sdt = 1234560;
    my_data.namsinh = 2002;


    if (ret = pthread_create(&thread_id1, NULL, &thr_handle, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }
    if (ret = pthread_create(&thread_id2, NULL, &thr_handle, &my_data))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    return 0;
}