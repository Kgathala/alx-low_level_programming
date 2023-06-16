#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * main - Entry point of the program
 *
 * Return: Always 1 (indicating failure)
 */
int main(void)
{
    int fd;
    ssize_t len;
    const char *message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

    len = strlen(message);
    fd = open("/dev/stderr", O_WRONLY);
    if (fd != -1)
    {
        write(fd, message, len);
        close(fd);
    }
    return (1);
}
