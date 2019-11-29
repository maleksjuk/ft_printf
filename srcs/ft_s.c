/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:39:52 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/29 20:56:30 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*num_null(void)
{
	char	*num;

	num = ft_strnew(7);
	ft_strcpy(num, "(null)\0");
	return (num);
}

void		s_minus(t_printf **p, char *num, char *str, int tab[2])
{
	int	i;

	if ((*p)->precision > -1 && ((*p)->precision < (*p)->width ||
		(*p)->width == 0))
	{
		i = tab[0];
		tab[0] = 0;
		while (((*p)->precision - tab[1] > 0) && (num[tab[0]]))
			str[tab[1]++] = num[tab[0]++];
		tab[0] = 0;
		while ((*p)->precision - tab[0] > i && (*p)->width > 0)
		{
			str[tab[1]++] = ' ';
			i++;
		}
		tab[1] += simvol_out(p, tab[1], ' ', &str[tab[1]]);
	}
	else
	{
		ft_strcpy(str, num);
		tab[1] += tab[0];
		tab[1] += simvol_out(p, tab[0], ' ', &str[tab[1]]);
	}
}

void		s_zero(t_printf **p, char *num, char *str, int tab[2])
{
	if ((*p)->precision > -1 && ((*p)->precision < (*p)->width ||
		(*p)->width == 0))
	{
		while ((*p)->width - (*p)->precision > tab[1])
			str[tab[1]++] = '0';
		tab[0] = 0;
		while ((*p)->precision - tab[0] > 0)
			str[tab[1]++] = num[tab[0]++];
	}
	else
	{
		if ((*p)->width > tab[0])
			while (tab[1] < (*p)->width - tab[0])
				str[tab[1]++] = '0';
		else
			while ((*p)->width + tab[1] < tab[0] - 1)
				str[tab[1]++] = '0';
		ft_strcpy(&str[tab[1]], num);
	}
}

void		s_default(t_printf **p, char *num, char *str, int tab[2])
{
	int	i;

	if ((*p)->precision > -1 && ((*p)->precision <= (*p)->width ||
		(*p)->width == 0))
	{
		while ((*p)->width - (*p)->precision > tab[1])
			str[tab[1]++] = ' ';
		i = 0;
		while ((*p)->precision - i > tab[0] && (*p)->width > 0)
		{
			str[tab[1]++] = ' ';
			i++;
		}
		tab[0] = 0;
		while ((*p)->precision - tab[0] > 0)
			str[tab[1]++] = num[tab[0]++];
	}
	else
	{
		tab[1] += simvol_out(p, tab[0], ' ', str);
		ft_strcpy(&str[tab[1]], num);
	}
}

void		s_return(t_printf **p, char *str)
{
	if ((*p)->final_str[0] == '\0')
		(*p)->final_str = str;
	else
	{
		(*p)->final_str = ft_strjoin((*p)->final_str, str);
		free(str);
	}
}

int			ft_s(t_printf **p)
{
	char	*num;
	char	*str;
	int		tab[2];

	num = (*p)->str_val;
	if (!num)
		num = num_null();
	tab[0] = ft_strlen(num);
	tab[1] = max_val(tab[0], max_val((*p)->precision, (*p)->width));
	str = ft_strnew(tab[1] + 1);
	if (!str)
		return (1);
	if (ft_strequ(num, ""))
		(*p)->precision = -1;
	tab[1] = 0;
	if ((*p)->minus)
		s_minus(p, num, str, tab);
	else if ((*p)->zero)
		s_zero(p, num, str, tab);
	else
		s_default(p, num, str, tab);
	s_return(p, str);
	return (0);
}
