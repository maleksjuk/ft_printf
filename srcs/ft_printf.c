#include "../includes/ft_printf.h"

int 	ft_final(t_printf **p)
{
	ft_putstr((*p)->final_str);
	(*p)->final_len = ft_strlen((*p)->final_str);
	free((*p)->final_str);
	free(*p);
	return (0);
}

int 	ft_search_spec(t_printf **p, int i)
{
	while (((*p)->format[i]) != '\0' && (*p)->format[i] != '%')
		i++;
	if ((*p)->format[i] == '%')
	{
		if (!(*p)->final_str)
		{
			(*p)->final_str = (char *)malloc(sizeof((*p)->final_str) * i + 1);
			(*p)->final_str = ft_strncpy((*p)->final_str, (*p)->format, i);
		}
//		else
//		{
//			(*p)->final_str = ft_strjoin((*p)->final_str, );
//		}
		i++;
	}
	else if ((*p)->format[i] == '\0')
	{
		(*p)->final_str = (char *)malloc(sizeof((*p)->final_str) * i + 1);
		(*p)->final_str = ft_strcpy((*p)->final_str, (*p)->format);
		return (-1);
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

int 	ft_search_size(t_printf **p, int i)
{
	if ((*p)->format[i] != '\0' &&
			ft_strchr((*p)->size_mask, (*p)->format[i]))
	{
		if ((*p)->format[i] == (*p)->format[i + 1])
		{
			(*p)->size = (*p)->format[i] - 32;
			i = i + 2;
		}
		else
		{
			(*p)->size = (*p)->format[i];
			i++;
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
		ft_putstr("wrong type\n");
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
	if (i < 6)
		ft_type[i](p);
	return (0);
}

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
		val = (unsigned int)(va_arg((*p)->ap, unsigned int));
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
		val = (int)(va_arg((*p)->ap, int));
	(*p)->int_val = (intmax_t)val;
}

void	ft_choose_value(t_printf **p)
{
	if ((*p)->type == 'u')
		ft_uint_value(p);
	else
		ft_int_value(p);
}

int 	ft_pars(t_printf **p)
{
	if (((*p)->index = ft_search_spec(p, (*p)->index)) == -1)
		return (-1);
	(*p)->index = ft_search_flags(p, (*p)->index);
	(*p)->index = ft_search_width(p, (*p)->index);
	(*p)->index = ft_search_precision(p, (*p)->index);
	(*p)->index = ft_search_size(p, (*p)->index);
	(*p)->index = ft_search_type(p, (*p)->index);
	ft_putstr((*p)->final_str);
	ft_choose_value(p);
	ft_choose_type(p);
	return (0);
}

int 	ft_construct(t_printf **p)
{
	(*p)->final_len = 0;
	(*p)->minus = 0;
	(*p)->plus = 0;
	(*p)->zero = 0;
	(*p)->hash = 0;
	(*p)->space = 0;
	(*p)->width = 0;
	(*p)->precision = 0;
	(*p)->int_val = 0;
	(*p)->uint_val = 0;
	(*p)->type = 0;
	(*p)->size = 0;
	(*p)->final_str = NULL;
	(*p)->spec_mask = "diouxX";
	(*p)->size_mask = "hl";
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
		if (ft_pars(&p) == -1)
			break ;
	}
	ft_final(&p);
	va_end(p->ap);
//	ft_putchar('\n');
	return (p->final_len);
}

int		main(void)
{
//	ft_printf("abc %*hd def %.5hhi %3lld %.*li", 2, 1, 4, 3, 5, 6);
	ft_printf("abc %u   b", 2);
	return (0);
}
