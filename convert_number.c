#include"main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 *
 * @p: the argument pointer
 * @params: the argument struct
 *
 * Return:bytes printed
*/

int print_hex(va_list p, params_t *params)
{
	unsigned long one;
	int c = 0;
	char *str;

	if (params->one_modifier)
		one = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		one = (unsigned short int)va_arg(p, unsigned int);
	else
		one = (unsigned int)va_arg(p, unsigned int);

	str = convert(one, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hash_flag && 1)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;

	return (c += print_num(str, params));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 *
 * @p: the argument pointer
 * @params: the argument struct
 *
 * Return:bytes printed
*/

int print_HEX(va_list p, params_t *params)
{
	unsigned long one;
	int c = 0;
	char *str;

	if (params->one_modifier)
		one = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		one = (unsigned short int)va_arg(p, unsigned int);
	else
		one = (unsigned int)va_arg(p, unsigned int);

	str = convert(one, 16, CONVERT_UNSIGNED, params);
	if (params->hash_flag && 1)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_num(str, params));
}

/**
 * print_binary - prints unsigned binary number
 *
 * @p: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
*/
int print_binary(va_list p, params_t *params)
{
	unsigned int n = va_arg(p, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hash_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_num(str, params));
}

/**
 * print_octal - prints unsigned octal numbers
 *
 * @p: the argument pointer
 * @params: the parameter struct
 *
 * Return: bytes printed
*/

int print_octal(va_list p, params_t *params)
{
	unsigned long one;
	char *str;
	int c = 0;

	if (params->one_modifier)
		one = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		one = (unsigned short int)va_arg(p, unsigned int);
	else
		one = (unsigned int)va_arg(p, unsigned int);
	str = convert(one, 8, CONVERT_UNSIGNED, params);

	if (params->hash_flag && one)
		*str = '0';
	params->unsign = 1;
	return (c += print_num(str, params));
}
