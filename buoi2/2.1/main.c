#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main()
{
    struct  stat sb;    
    int fd;
    fd = open("test.txt", O_RDWR);
    
    fstat(fd, &sb);
    printf("File type:                ");
    switch (sb.st_mode & __S_IFMT) {
    case __S_IFBLK:  printf("block device\n");            break;
    case __S_IFCHR:  printf("character device\n");        break;
    case __S_IFDIR:  printf("directory\n");               break;
    case __S_IFIFO:  printf("FIFO/pipe\n");               break;
    case __S_IFLNK:  printf("symlink\n");                 break;
    case __S_IFREG:  printf("regular file\n");            break;
    case __S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }
    printf("Last file modification:   %s", ctime(&sb.st_mtime));
    printf("File size:                %ld bytes\n", sb.st_size);

    close(fd);
    return 0;
}