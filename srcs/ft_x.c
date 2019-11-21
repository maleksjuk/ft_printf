/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:29:44 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/21 17:53:21 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_x_universe(t_printf **p, char c, char x)
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
	len = transform(num, 16, c, trans) + 1;
	len_str = ft_max(len, ft_max((*p)->precision, (*p)->width));
	str = ft_strnew(len_str + 1);
	if (!str)
		return (1);
	if ((*p)->hash)
		len += 2;
	if ((*p)->minus)
	{
		if ((*p)->hash)
		{
			str[i++] = '0';
			str[i++] = x;
		}
		i += for_precision(p, len - (*p)->hash * 2, &str[i]);
		ft_strcpy(&str[i], trans);
		if ((*p)->hash)
			i += len - 2;
		else
			i += len;
		i += simvol_out(p, len, ' ', &str[i]);
	}
	else if ((*p)->zero && (*p)->precision < 0)
	{
		if ((*p)->hash)
		{
			str[i++] = '0';
			str[i++] = x;
		}
	//	i += for_precision(p, len, &str[i]);
		i += simvol_out(p, len, '0', &str[i]);
		ft_strcpy(&str[i], trans);
	}
	else
	{
		if ((*p)->precision > 0)
			i += simvol_out(p, len + (*p)->precision - 1, ' ', &str[i]);
		else
			i += simvol_out(p, len, ' ', &str[i]);
		if ((*p)->hash)
		{
			str[i++] = '0';
			str[i++] = x;
			len -= 2;
		}
		i += for_precision(p, len, &str[i]);
		ft_strcpy(&str[i], trans);
	}
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	free(trans);
	return (0);
}

// integer '16' undigned 0123456789abcdef
int		ft_x(t_printf **p)
{
	return (ft_x_universe(p, 'a', 'x'));	
}

// integer '16' unsigned 0123456789ABCDEF
int		ft_X(t_printf **p)
{
	return (ft_x_universe(p, 'A', 'X'));
}