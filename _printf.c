#include "main.h"

/**
* _printf - printf function
* @format: format
* Return: sum
*/
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list p;
	char *pr, *start;
	params_t params = PARAMS_INIT;

	va_start(p, format);

	if (!format || (format[0] == '%' && !format[1]))
	return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);

	for (pr = (char *)format; *pr; pr++)
	{

	init_params(&params, &p);
	if (*pr != '%')
	{
		sum += _putchar(*pr);
		continue;
	}
	start = pr;
	pr = get_width(pr, &params, p);
	pr = get_precision(pr, &params, p);
	if (get_modifier(pr, &params))
		pr++;
	if (!get_specifier(pr))
		sum += print_from_to(start, pr, params.one_modifier ||
		params.h_modifier ? pr - 1 : 0);
	else
	sum += get_print_func(pr, p, &params);
	}

	_putchar(BUF_FLUSH);
	va_end(p);
	return (sum);
}
