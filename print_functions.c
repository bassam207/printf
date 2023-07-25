#include"main.h"

/**
 * print_char - prints character
 *
 * @p: argument pointer
 * @params: the parameter struct
 *
 * Return: number chars printed
*/

int print_char(va_list p, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, va_arg(p, int);

	if (params->minus_flag)
		sum += _puthcar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 *
 * @p: argument pointer
 * @params: the parameters struct
 *
 * Retrun: number chars printed
*/

int print_int(va_list p, params_t *params)
{
	long l;
	
	if (params->l_modifier)
		l = va_arg(p, long);
	else if (params->h_modifier)
		l = (short int)va_arg(p, int);
	else
		l = (int)va_arg(p, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 *
 * @P: argument pointer
 * @params: the parameter struct
 *
 * Return: number chars printed
*/

int print_string(va_list p, params_t *params)
{
	char *str = va_arg(p, char *), pad_char = ' ';
	unsigned int pad = 0, sum 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UNIT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 *
 * @p: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
*/

int prunt_percrnt(va_list p, params_t *params)
{
	(void)p;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_s - custom format specifier
 *
 * @p: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
*/

int print_s(va_list p, params_t *params)
{
	char *str = va_arg(p, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar ('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}