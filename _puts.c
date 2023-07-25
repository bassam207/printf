#include "main.h"

/**
* _puts - prints str with newline
* @str: str tp print
* Return: void
*/
int _puts(char *str)
{
	char *s = str;

	while (*str)
		_putchar(*str++);
	return (str - s);
}

/**
* _putchar - print char c to stdout
* @c: the char to print
* Return: 1 on success
* on error, -1
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
	return (1);
}
