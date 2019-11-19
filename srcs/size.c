#include "../includes/ft_printf.h"

void	ft_uint_value(t_printf **p)
{
	uintmax_t val;

	if ((*p)->size == 'H')
		val = (unsigned char)(va_arg((*p)->ap, unsigned int));
	else if ((*p)->size == 'h')
		val = (unsigned short int)(va_arg((*p)->ap, unsigned int));
	else if ((*p)->size == 'L')
		val = (unsigned long long int)(va_arg((*p)->ap, unsigned long long int));
	else if ((*p)->size == 'l')
		val = (unsigned long int)(va_arg((*p)->ap, unsigned long int));
	else
		val = (unsigned int)va_arg((*p)->ap, unsigned int);
	(*p)->uint_val = (uintmax_t)val;
}

void	ft_int_value(t_printf **p)
{
	intmax_t val;

	if ((*p)->size == 'H')
		val = (signed char)(va_arg((*p)->ap, int));
	else if ((*p)->size == 'h')
		val = (short int)(va_arg((*p)->ap, int));
	else if ((*p)->size == 'L')
		val = (long long int)(va_arg((*p)->ap, long long int));
	else if ((*p)->size == 'l')
		val = (long int)(va_arg((*p)->ap, long int));
	else
		val = (int)va_arg((*p)->ap, int);
	(*p)->int_val = (intmax_t)val;
}

void	ft_choose_value(t_printf **p)
{
	if ((*p)->type == 'u' || (*p)->type == 'o' ||
		(*p)->type == 'x' || (*p)->type == 'X')
		ft_uint_value(p);
	else if ((*p)->type == 's')
		(*p)->str_val = (char *)(va_arg((*p)->ap, char *));
	else if ((*p)->type == 'f')
		(*p)->double_val = (double)(va_arg((*p)->ap, double));
	else
		ft_int_value(p);
}