/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:09:55 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/17 17:44:25 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_c(t_printf **p)
{
	char	c;
	char	*str;
	int		i;

	c = (char)(*p)->int_val;
	i = ft_max((*p)->precision, (*p)->width);
	str = ft_strnew(i + 1);
	if (!str)
		return (1);
	i = 0;
	if ((*p)->width > 1 && !(*p)->minus)
		i = i + simvol_out(p, 1, ' ', &str[i]);
	str[i++] = c;
	if ((*p)->minus)
		i = i + simvol_out(p, 1, ' ', &str[i]);
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	return (0);
}

int ft_s(t_printf **p)
{
	char	*num;
	int		len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	num = (*p)->str_val; //va_arg((*p)->ap, int);
	len = ft_strlen(num);
	str = ft_strnew(len + (*p)->width + (*p)->precision + (*p)->space + 1);
	if (!str)
		return (1);
	if ((*p)->precision && (*p)->width)
		while ((*p)->width > (*p)->precision && !((*p)->minus))
		{
			str[i++] = ' ';
			((*p)->width)--;
		}
//	if ((*p)->zero)							// FLAG 0
//		i += simvol_out(p, len, '0', &str[i]);
	if ((*p)->width > len && !(*p)->minus)
		i += simvol_out(p, len, ' ', &str[i]);
	j = 0;
	if ((*p)->precision)// ft_putnbr(num); !!!!!!!!!!!!!!!!!!!!
		while ((*p)->precision > j)
			str[i++] = num[j++];
	else
		while (len > j)
			str[i++] = num[j++];
	if ((*p)->minus)						// FLAG -
		i += simvol_out(p, len, ' ', &str[i]);
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
//	ft_putstr((*p)->str_val);
	return (0);
}

int	ft_p(t_printf **p);
