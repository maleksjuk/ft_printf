/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:30:22 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/21 14:30:47 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// integer '10' signed; FLAGS 0+-_
int		ft_d(t_printf **p)
{
	intmax_t	num;
	int			len;
	int			len_str;
	char		*str;
	int			i;
	int			znak;

	i = 0;
	znak = 0;
	num = (*p)->int_val;
	if (num < 0 || (*p)->plus || (*p)->space)
		znak = 1;
	len = len_nbr(num);
	if (znak)
		len++;
	len_str = ft_max(len, ft_max((*p)->precision, (*p)->width)) + znak;
	str = ft_strnew(len_str + 1);
	if (!str)
		return (1);
	if ((*p)->minus)
	{
		if (num < 0)
		{
			str[i++] = '-';
			num *= -1;
		}
		else if ((*p)->plus && num > 0)
			str[i++] = '+';
		else if ((*p)->space && num >= 0)
			str[i++] = ' ';
		// if ((*p)->precision > -1 && (*p)->width && (*p)->precision + 1 < (*p)->width)
		// 	i--;
		i += for_precision(p, len - znak, &str[i]);
		ft_strcpy(&str[i], ft_itoa(num));
		if (znak)
			i--;
		i += len;
		i += simvol_out(p, len, ' ', &str[i]);
	}
	else if ((*p)->zero && (*p)->precision < 0)
	{
		if (num < 0)
		{
			str[i++] = '-';
			num *= -1;
		}
		else if ((*p)->plus && num > 0)
			str[i++] = '+';
		else if ((*p)->space)
			str[i++] = ' ';
		i += for_precision(p, len - znak, &str[i]);
		i += simvol_out(p, len, '0', &str[i]);
		ft_strcpy(&str[i], ft_itoa(num));
	}
	else
	{
		if ((*p)->precision > 0)
			i += simvol_out(p, len + (*p)->precision - len + znak, ' ', &str[i]);
		else
			i += simvol_out(p, len, ' ', &str[i]);
		if (num < 0)
		{
			str[i++] = '-';
			num *= -1;
		}
		else if ((*p)->plus && num > 0)
			str[i++] = '+';
		else if ((*p)->space && num >= 0)
			str[i++] = ' ';
		i += for_precision(p, len - znak, &str[i]);
		ft_strcpy(&str[i], ft_itoa(num));
	}
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	return (0);
}

// integer '10' signed
int		ft_i(t_printf **p)
{
	return (ft_d(p));
}