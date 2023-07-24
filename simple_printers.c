#include"main.h"

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

	while (stsrt <= stop)
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

int print_rev(va_list p, params_ *params)
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
	int k, index;
	int count = 0;

	char arr[] =
		"NOPQRETUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(p, char *);
	(void)params;

	k = 0;;
	index = 0;
	while (a[k])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
			|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}