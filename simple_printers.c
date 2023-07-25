#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 *
 * @starts: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Retuen: number bytes printed
*/

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * prints_rev - prints string in revrse
 *
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
*/

int print_rev(va_list p, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(p, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 *
 * @ap: string
 * @params: the parameters struct
 *
 * Return: numbers bytes printed
*/

int print_rot13(va_list p, params_t *params)
{
	int i, index;
	int count = 0;

	char arr[] =
		"NOPQRETUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(p, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[k] >= 'A' && a[k] <= 'Z')
			|| (a[k] >= 'a' && a[k] <= 'z'))
		{
			index = a[k] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
