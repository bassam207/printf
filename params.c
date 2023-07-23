#include "main.h"

/**
* init_params - clears struct fields and reset buf
* @params: the struct params
* @p: the arg pointer
* Return: void
*/
void init_params(params_t *params, va_list p)
{
	params->unsign = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->hash_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->h_modifier = 0;
	params->one_modifier = 0;
	(void)p;
}
