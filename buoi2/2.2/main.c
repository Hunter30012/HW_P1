#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;
    fd = open("test.txt", O_WRONLY | O_APPEND);
    lseek(fd, 0, SEEK_SET);
    write(fd, "123", sizeof("123"));
    close(fd);
    return 0;
}