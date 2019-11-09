#include "../includes/ft_printf.h"

int 	ft_search_spec(t_printf **p, int i)
{
	while (((*p)->format[i]) != '\0' && (*p)->format[i] != '%')
		ft_putchar((*p)->format[i++]);
	if ((*p)->format[i] == '%')
		i++;
	return (i);
}

int 	ft_pars(t_printf **p)
{
	int i;

	i = ft_search_spec(p, 0);

	return (0);
}

int 	ft_construct(const char* format, t_printf **p)
{
	(*p)->type = 0;
	(*p)->format = (char *)format;
	(*p)->spec_mask = "scSCdDiuUoOxXbp%";
	return (0);
}

int		ft_printf(const char* format, ...)
{
	t_printf *p;

	if (!(p = (t_printf*)malloc(sizeof(p))))
		return (-1);
	ft_construct(format, &p);
	va_start(p->ap, format);
	ft_pars(&p);
	va_end(p->ap);
	ft_putchar('\n');
	return (0);
}

int		main(void)
{
	ft_printf("abc %i", 1);
	//printf("abc %i", -1);
	return (0);
}