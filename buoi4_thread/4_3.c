#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char hoten[30];
    char ngaysinh[30];
    char quequan[30];
}sinhvien_t;

#define TRUE 1
#define FLASE 0

pthread_t  thread_id1;
pthread_t  thread_id2;
pthread_t  thread_id3;
pthread_mutex_t lock_sv = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
sinhvien_t sv;
int flag = FLASE;

void *thr_handle1(void *args)
{
    pthread_mutex_lock(&lock_sv);
    while(1)
    {
        pthread_cond_wait(&cond, &lock_sv);
        memset(&sv, 0, sizeof(sv));
        printf("Nhap ho ten: ");
        scanf("%s", sv.hoten);
        printf("Nhap ngay sinh: ");
        scanf("%s", sv.ngaysinh);
        printf("Nhap quequan: ");
        scanf("%s", sv.quequan);
        flag = TRUE;
    }
    pthread_mutex_unlock(&lock_sv);
    pthread_exit(NULL);
}

void *thr_handle2(void *args)
{
    int fd;
    fd = open("thongtinsinhvien.txt", O_WRONLY | O_CREAT);
    pthread_mutex_lock(&lock_sv);
    write(fd, sv.hoten, sizeof(sv.hoten));
    write(fd, sv.hoten, sizeof(sv.ngaysinh));
    write(fd, sv.hoten, sizeof(sv.quequan));
    pthread_mutex_unlock(&lock_sv);
    close(fd);
    pthread_exit(NULL);
}

void *thr_handle3(void *args)
{
    pthread_mutex_lock(&lock_sv);
    
    printf("Nhap thong tin sinh vien\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock_sv);
    pthread_exit(NULL);
}


int main(int argc, char const *argv[])
{
    int fd;
    int ret;

    if (ret = pthread_create(&thread_id1, NULL, &thr_handle1, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }
    if (ret = pthread_create(&thread_id2, NULL, &thr_handle2, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }
    if (ret = pthread_create(&thread_id3, NULL, &thr_handle3, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
    return 0;
}