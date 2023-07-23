#include "main.h"

/**
* get_specifier - finds format func
* @s: format str
* Return: number of bytes printed
*/
int (*get_specifier(char *s))(va_list p, params_t  * params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_str},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"X", print_HEX},
		{"x", print_hex},
		{"p", print_address},
		{"s", print_s},
		{"r", print_rev},
		{"R", print_rot},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
* get_print_func - finds format function
* @s: format string
* @p: arg pointer
* @params: parameters struct
* Return: number of bytes printed
*/
int get_print_func(char *s, va_list p, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);
	
	if (f)
		return (f(p, params));
	return (0);
}

/**
* get_flag - finds flag function
* @s: format str
* @params: parameters struct
* Return: if flag was true
*/
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hash_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
* get_modifier - finds modifier func
* @s: format str
* @params: parameters struct
* Return: if modifier was valid
*/
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case '1':
			i = params->one_modifier = 1;
			break;
	}
	return (i);
}

/**
* get_width - get width from format str
* @s: format str
* @params: the parameters struct
* @p: the arg pointer
* Rturn: new pointer
*/
char *get_width(char *s, params_t *params, va_list p)
{
	int w = 0;

	if (*s == '*')
	{
		w = va_arg(p, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			w = w * 10 + (*s++ - '0');
	}
	params->width = w;
	return (s);
}
