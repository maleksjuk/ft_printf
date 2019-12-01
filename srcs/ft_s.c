/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:39:52 by obanshee          #+#    #+#             */
/*   Updated: 2019/12/01 15:57:55 by obanshee         ###   ########.fr       */
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

void		s_return(t_printf **p, char *str)
{
	(*p)->final_len += ft_strlen(str);
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
