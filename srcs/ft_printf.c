#include "../includes/ft_printf.h"

int 	ft_search_spec(t_printf **p, int i)
{
	while (((*p)->format[i]) != '\0' && (*p)->format[i] != '%')
		ft_putchar((*p)->format[i++]);
	if ((*p)->format[i] == '%')
		i++;
	else if ((*p)->format[i] == '\0')
	{
		free(*p);
		exit(EXIT_SUCCESS);
	}
	return (i);
}

int 	ft_search_flags(t_printf **p, int i)
{
	while (((*p)->format[i]) != '\0' && !(ft_strchr((*p)->spec_mask, (*p)->format[i])))
	{
		if ((*p)->format[i] == '-')
			(*p)->minus = 1;
		else if ((*p)->format[i] == '+')
			(*p)->plus = 1;
		else if ((*p)->format[i] == '#')
			(*p)->hash = 1;
		else if ((*p)->format[i] == '0')
			(*p)->zero = 1;
		else if ((*p)->format[i] == ' ')
			(*p)->space = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int 	ft_search_width(t_printf **p, int i)
{
	if ((*p)->format[i] != '\0' && !(ft_strchr((*p)->spec_mask, (*p)->format[i])))
	{
		if ((*p)->format[i] == '*')
		{
			(*p)->width = va_arg((*p)->ap, int);
			i++;
		}
		else if ((*p)->format[i] >= '0' && (*p)->format[i] <= '9')
		{
			while ((*p)->format[i] >= '0' && (*p)->format[i] <= '9')
				(*p)->width = (*p)->width * 10 + ((*p)->format[i++] - '0');
		}
	}
	return (i);
}

int 	ft_search_precision(t_printf **p, int i)
{
	if ((*p)->format[i] != '\0' && !(ft_strchr((*p)->spec_mask, (*p)->format[i])))
	{
		if ((*p)->format[i] == '.')
		{
			i++;
			if ((*p)->format[i] == '*')
			{
				(*p)->precision = va_arg((*p)->ap, int);
				i++;
			}
			else if ((*p)->format[i] >= '0' && (*p)->format[i] <= '9')
			{
				while ((*p)->format[i] >= '0' && (*p)->format[i] <= '9')
					(*p)->precision = (*p)->precision * 10 + ((*p)->format[i++] - '0');
			}
		}
	}
	return (i);
}

int 	ft_search_type(t_printf **p, int i)
{
	if ((*p)->format[i] != '\0' &&
		ft_strchr((*p)->spec_mask, (*p)->format[i]))
		(*p)->type = (*p)->format[i];
	else
		ft_putstr("wrong specifer\n");
	return (++i);
}

int 	ft_choose_type(t_printf **p)
{
	int i;

	i = -1;
	int (*ft_type[6])(t_printf**) = {ft_d, ft_i, ft_o, ft_u, ft_x, ft_X};
	while ((*p)->spec_mask[++i])
		if ((*p)->spec_mask[i] == (*p)->type)
			break;
	if (i < 3)
		ft_type[i](p);
	return (0);
}

int 	ft_pars(t_printf **p)
{
	(*p)->index = ft_search_spec(p, (*p)->index);
	(*p)->index = ft_search_flags(p, (*p)->index);
	(*p)->index = ft_search_width(p, (*p)->index);
	(*p)->index = ft_search_precision(p, (*p)->index);
	(*p)->index = ft_search_type(p, (*p)->index);
	ft_choose_type(p);
	return (0);
}

int 	ft_construct(t_printf **p)
{
	(*p)->minus = 0;
	(*p)->plus = 0;
	(*p)->zero = 0;
	(*p)->hash = 0;
	(*p)->space = 0;
	(*p)->type = 0;
	(*p)->width = 0;
	(*p)->precision = 0;
	(*p)->spec_mask = "diouxX";
	return (0);
}

int		ft_printf(const char* format, ...)
{
	t_printf *p;

	if (!(p = (t_printf*)malloc(sizeof(p))))
		return (-1);
	va_start(p->ap, format);
	p->index = 0;
	p->format = (char *)format;
	while (format[p->index] != '\0')
	{
		ft_construct(&p);
		ft_pars(&p);
	}
	va_end(p->ap);
	ft_putchar('\n');
	return (0);
}

int		main(void)
{
	ft_printf("abc $%o$\n", 10);
	return (0);
}