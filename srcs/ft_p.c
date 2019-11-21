/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:57:39 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/21 16:46:07 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_p(t_printf **p)
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
	len = transform(num, 16, 'a', trans) + 1;
	len_str = ft_max(len, ft_max((*p)->precision, (*p)->width)) + 2;
	str = ft_strnew(len_str + 2);
	if (!str)
		return (1);
	len += 2;
	if ((*p)->minus)
	{
        str[i++] = '0';
        str[i++] = 'x';
		i += for_precision(p, len - 2, &str[i]);
		ft_strcpy(&str[i], trans);
		i += len - 2;
		i += simvol_out(p, len, ' ', &str[i]);
	}
	else if ((*p)->zero && (*p)->precision < 0)
	{
        str[i++] = '0';
        str[i++] = 'x';
	//	i += for_precision(p, len, &str[i]);
		i += simvol_out(p, len, '0', &str[i]);
		ft_strcpy(&str[i], trans);
	}
	else
	{
		if ((*p)->precision > 0)
			i += simvol_out(p, len + (*p)->precision - 2, ' ', &str[i]);
		else
			i += simvol_out(p, len, ' ', &str[i]);
        str[i++] = '0';
        str[i++] = 'x';
        len -= 2;
		i += for_precision(p, len, &str[i]);
		ft_strcpy(&str[i], trans);
	}
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	free(trans);
    return (0);
}
