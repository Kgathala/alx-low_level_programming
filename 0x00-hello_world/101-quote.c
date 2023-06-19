#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>

#define STDERR_FILENO 2

/**
 * custom_print - Writes a string to stderr using write system call
 * @str: The string to be written
 */
void custom_print(const char *str)
{
	const int str_len = strlen(str);
	syscall(SYS_write, STDERR_FILENO, str, str_len);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 1
 */
int main(void)
{
	const char *message = "\"and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	custom_print(message);

	return 1;
}

