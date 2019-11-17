#include "../includes/ft_printf.h"

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

int 	ft_pars(t_printf **p)
{
	if (((*p)->index = ft_search_spec_1(p, (*p)->index)) == -1)
		return (-1);
	(*p)->index = ft_search_flags(p, (*p)->index);
	(*p)->index = ft_search_width(p, (*p)->index);
	(*p)->index = ft_search_precision(p, (*p)->index);
	(*p)->index = ft_search_size(p, (*p)->index);
	(*p)->index = ft_search_type(p, (*p)->index);
	ft_choose_value(p);
	ft_choose_type(p);
	return (0);
}