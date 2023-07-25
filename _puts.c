#include "main.h"

/**
* _puts - prints str with newline
* @str: str to print
* Return: void
*/
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
}

/**
* _putchar - print char c to stdout
* @c: the char to print
* Return: 1 on success, -1 on error
*/
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (c != BUF_FLUSH ? 1 : -1);
}

