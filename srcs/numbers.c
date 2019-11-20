/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:31:12 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/20 19:27:11 by obanshee         ###   ########.fr       */
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
		if ((*p)->precision > 0)
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

int		ft_x_universe(t_printf **p, char c)
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
			str[i++] = 'x';
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
			str[i++] = 'x';
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
			str[i++] = 'x';
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
	return (ft_x_universe(p, 'a'));	
}

// integer '16' unsigned 0123456789ABCDEF
int		ft_X(t_printf **p)
{
	return (ft_x_universe(p, 'A'));
}