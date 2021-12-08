#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

#define DEVICE_PATH "/dev/mychardev"
char message[] = "hello there";

int main()
{
    //***************open**************
    int dev = open(DEVICE_PATH, O_RDWR);
    if (dev == -1)
    {
        printf("open is not successful\n");
        return -1;
    }
    else
    {
        printf("open is successful\n");
    }

    //***************write**************
    size_t nbytes = strlen(message);
    ssize_t bytesWritten = write(dev, message, nbytes);

    if (bytesWritten < 0)
    {
        printf("ret is %zu. Write is not successful\n", bytesWritten);
    }
    else
    {
        printf("write is successfull\n");
    }

    //***************read**************

    char readBuf[12];
    ssize_t readBytes = read(dev, readBuf, nbytes);
    printf("bytes %ld\n", readBytes);
    if (readBytes < 0)
    {
        printf("ret is %zu read is not successful\n", readBytes);
    }
    else
    {
        if (readBytes > bytesWritten)
        {
            readBytes = bytesWritten;
        }

        printf("%zu number of bytes readed, msg: %s\n", readBytes, readBuf);
    }

    //***************close**************
    close(dev);
    return 0;
}
