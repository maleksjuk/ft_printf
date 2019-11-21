/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:31:17 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/21 14:53:28 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// integer '8' unsigned
int		ft_o(t_printf **p)
{
	uintmax_t	num;
	char		*str;
	char		*trans;
	int			len;
	int			len_str;
	int			i;

	i = 0;
	num = (*p)->uint_val;
	trans = ft_strnew(len_nbr(num) * 2);
	if (!trans)
		return (1);
	len = transform(num, 8, '0', trans) + 1;
	len_str = ft_max(len, ft_max((*p)->precision, (*p)->width));
	str = ft_strnew(len_str + 1);
	if (!str)
		return (1);
	if ((*p)->precision > len)
		(*p)->hash = 0;
	if ((*p)->hash)
		len++;
	if ((*p)->minus)
	{
		if ((*p)->hash)
			str[i++] = '0';
		i += for_precision(p, len - (*p)->hash, &str[i]);
		ft_strcpy(&str[i], trans);
		if ((*p)->hash)
			i += len - 1;
		else
			i += len;
		i += simvol_out(p, len, ' ', &str[i]);
	}
	else if ((*p)->zero && (*p)->precision < 0)
	{
		if ((*p)->hash)
			str[i++] = '0';
		i += for_precision(p, len, &str[i]);
		i += simvol_out(p, len, '0', &str[i]);
		ft_strcpy(&str[i], trans);
	}
	else
	{
		if ((*p)->precision > len)
			i += simvol_out(p, len + (*p)->precision - len, ' ', &str[i]);
		else
			i += simvol_out(p, len, ' ', &str[i]);
		if ((*p)->hash)
		{
			str[i++] = '0';
			len--;
		}
		i += for_precision(p, len, &str[i]);
		ft_strcpy(&str[i], trans);
	}
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	free(trans);
	return (0);
}
