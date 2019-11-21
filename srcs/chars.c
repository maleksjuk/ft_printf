/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:09:55 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/21 19:05:25 by obanshee         ###   ########.fr       */
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
	if ((*p)->width > 1 && !(*p)->minus && !(*p)->zero)
		i = i + simvol_out(p, 1, ' ', &str[i]);
	else if ((*p)->zero && !(*p)->minus)
		i += simvol_out(p, 1, '0', &str[i]);
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

	num = (*p)->str_val;
	len = ft_strlen(num);
	i = ft_max(len, ft_max((*p)->precision, (*p)->width));
	str = ft_strnew(i + 1);
	if (!str)
		return (1);
	i = 0;
	if ((*p)->minus)
	{
		if ((*p)->precision > -1)
		{
			len = 0;
			while ((*p)->precision - i > 0)
				str[i++] = num[len++];
			i += simvol_out(p, i, ' ', &str[i]);
		}
		else
		{
			ft_strcpy(str, num);
			i += simvol_out(p, len, ' ', &str[i]);
		}
	}
	else if ((*p)->zero)
	{
		if ((*p)->precision > -1)
		{
			while ((*p)->width - (*p)->precision > i)
				str[i++] = '0';
			len = 0;
			while ((*p)->precision - len > 0)
				str[i++] = num[len++];
		}
		else
		{
			while ((*p)->width + i < len)
				str[i++] = '0';
			ft_strcpy(&str[i], num);
		}
	}
	else
	{
		if ((*p)->precision > -1)
		{
			while ((*p)->width - (*p)->precision > i)
				str[i++] = ' ';
			len = 0;
			while ((*p)->precision - len > 0)
				str[i++] = num[len++];
		}
		else
		{
			i += simvol_out(p, len, ' ', str);
			ft_strcpy(&str[i], num);
		}
	}
	if ((*p)->final_str[0] == '\0')
		(*p)->final_str = str;
	else
	{
		(*p)->final_str = ft_strjoin((*p)->final_str, str);
		free(str);
	}
	return (0);
}
