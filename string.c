#include "main.h"

/**
* get_precision - gets precision from format str
* @p: format str
* @params: parameters struct
* @p: arg pointer
* Return: new pointer
*/
char *get_precision(char *p, params_t  *params, va_list a)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(a, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++- '0');
	}
	params->precision = d;
	return (p);
}
