#include "../includes/ft_printf.h"

int 	ft_search_spec(t_printf **p, int i)
{
	while (((*p)->format[i]) != '\0' && (*p)->format[i] != '%')
		ft_putchar((*p)->format[i++]);
	if ((*p)->format[i] == '%')
		i++;
	return (i);
}

/*int 	ft_search_flags(t_printf **p, int i)
{
	while (((*p)->format[i]) != '\0' && (*p)->format[i] != '%')
		ft_putchar((*p)->format[i++]);
	if ((*p)->format[i] == '%')
		i++;
	return (i);
}*/

/*int 	ft_octet(t_printf **p)
{
	if (*p)
		return (0);
	return (1);
}

int		ft_double(t_printf **p)
{
	if (*p)
		return (0);
	return (1);
}

int		ft_int(t_printf **p)
{
	if (*p)
		return (0);
	return (1);
}*/

int 	ft_choose_type(t_printf **p)
{
	int i;

	i = -1;
	int (*ft_type[3])(t_printf**) = {ft_o, ft_d, ft_i};
	while ((*p)->spec_mask[++i])
		if ((*p)->spec_mask[i] == (*p)->type)
			break;
	ft_type[i](p);
	return (0);
}

int 	ft_pars(t_printf **p)
{
	int i;

	i = ft_search_spec(p, 0);
	//i = ft_search_flags(p, i);
	if ((*p)->format[i] != '\0' && ft_strchr((*p)->spec_mask, (*p)->format[i]))
		(*p)->type = (*p)->format[i];
	else
		ft_putstr("wrong specifer\n");
	ft_choose_type(p);
	return (0);

}

int 	ft_construct(const char* format, t_printf **p)
{
	(*p)->type = 0;
	(*p)->width = 0;
	(*p)->precision = 0;
	(*p)->format = (char *)format;
	(*p)->spec_mask = "odif";
	return (0);
}

int		ft_printf(const char* format, ...)
{
	t_printf	*p;

	if (!(p = (t_printf*)malloc(sizeof(p))))
		return (-1);
	va_start(p->ap, format);
	ft_construct(format, &p);
	ft_pars(&p);
	va_end(p->ap);
	ft_putchar(p->type);
	ft_putchar('\n');
	return (0);
}

int		main(void)
{
	ft_printf("abc %i new_args %i", 10, 20);
	return (0);
}