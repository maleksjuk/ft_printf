/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:30:57 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/21 14:31:07 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// integer '10' unsigned; FLAGS 0-
int		ft_u(t_printf **p)
{
	uintmax_t	num;
	int			len;
	int			len_str;
	char		*str;
	int			i;

	i = 0;
	num = (*p)->uint_val;
	len = len_nbr(num);
	len_str = ft_max(len, ft_max((*p)->precision, (*p)->width));
	str = ft_strnew(len_str + 1);
	if (!str)
		return (1);
	if ((*p)->minus)
	{
		i += for_precision(p, len, &str[i]);
		ft_strcpy(&str[i], ft_itoa(num));
		i += len;
		i += simvol_out(p, len, ' ', &str[i]);
	}
	else if ((*p)->zero && (*p)->precision < 0)
	{
		i += for_precision(p, len, &str[i]);
		i += simvol_out(p, len, '0', &str[i]);
		ft_strcpy(&str[i], ft_itoa(num));
	}
	else
	{
		if ((*p)->precision > 0)
			i += simvol_out(p, len + (*p)->precision - len, ' ', &str[i]);
		else
			i += simvol_out(p, len, ' ', &str[i]);
		i += for_precision(p, len, &str[i]);
		ft_strcpy(&str[i], ft_itoa(num));
	}
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	return (0);
}