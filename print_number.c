#include "main.h"

/**
 * _isdigit - checks if character is digit
 *
 * @c: the character to check
 *
 * Return: 1 if gigt, 0 otherwise
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 *
 * @s: the string whose length of string
 *
 * Return: string
*/

int _strlen(char *s)
{
	int k = 0;

	while (*s++)
		k++;
	return (k);
}

/**
 * print_num_right_shift - prints a number with options
 *
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
*/

int print_num_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar(' ');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar ('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_num_left_shift - prints a number with options
 *
 * @str: the base number as a string
 * @params: the parameter atruct
 *
 * Return: chars printed
*/

int print_num_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar (' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}

/**
* print_num - prints a number with options
*
* @str: the base number as a string
* @params: the paramrter struct
*
* Return: char printed
*/

int print_num(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_num_r_shift(str, params));
	else
		return (print_num_left_shift(str, params));
}
