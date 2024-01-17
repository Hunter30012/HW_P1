#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


pthread_t  thread_id1, thread_id2;

void *thr_handle(void *args)
{
    int fd;
    int i;
    fd = open("test.txt", O_RDWR | O_CREAT);

    for(i = 0;  i< 5000000; i++)
    {
        write(fd, "A", 1);
    }
    close(fd);

}

// void *thr2_handle(void *args)
// {

// }

int main(int argc, char const *argv[])
{
    int fd;
    int ret;
    int i;

    fd = open("test.txt", O_RDWR | O_CREAT);

    for(i = 0;  i< 10000000; i++)
    {
        write(fd, "A", 1);
    }
    close(fd);

    // if (ret = pthread_create(&thread_id1, NULL, &thr_handle, NULL))
    // {
    //     printf("pthread_create() error number=%d\n", ret);
    //     return -1;
    // }
    // if (ret = pthread_create(&thread_id2, NULL, &thr_handle, NULL))
    // {
    //     printf("pthread_create() error number=%d\n", ret);
    //     return -1;
    // }
    // pthread_join(thread_id1, NULL);
    // pthread_join(thread_id2, NULL);

    return 0;
}