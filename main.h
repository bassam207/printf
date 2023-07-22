#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
/**
* paramter - paramets struct
* @unsign: flag if unsigned value
* @plus_flag: true if plus_flag specified
* @space_flag: true if hashtag_flag specified
* @hash_flag: true if _flag specified
* @zero_flag: true if _flag specified
* @minus_flag: true if _flag specified
* @width: field width specified
* @percision: field percision specified
* @h_modifier: true if h_modifier specified
* @one_modifier: true if one_modifier specified
*/
typedef struct paramter
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hash_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int width : 1;
	unsigned int percision : 1;
	unsigned int h_modifier : 1;
	unsigned int one_modifier : 1;
} params_t;

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print function module */
int print_char(va_list p, params_t *params);
int print_int(va_list p, params_t *params);
int print_str(va_list p, params_t *params);
int print_percent(va_list p, params_t *params);
int print_s(va_list p, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list p, params_t *params);
int print_address(va_list p, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list p, params_t *params);
int get_print_func(char *s, va_list p, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list p);

/* convert_number.c module */
int print_hex(va_list p, params_t *params);
int print_HEX(va_list p, params_t *params);
int print_binary(va_list p, params_t *params);
int print_octal(va_list p, params_t *params);

/* simple_printer.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list p, params_t *params);
int print_rot(va_list p, params_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_num(char *str, params_t *params);
int print_num_r_shift(char *str, params_t *params);int print_num_l_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_lits p);

/* string_fields.c module */
char *get_precision(char *p, params_t *params, va_list p);

/* _printf.c module */
int _printf(const char *format, ...);

#endif

 
