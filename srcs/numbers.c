/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:31:12 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/17 19:37:54 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// integer '10' signed; FLAGS 0+-_
int		ft_d(t_printf **p)
{
	int		num;
	int		len;
	char	*str;
//	char	*trans;
	int		i;

	i = 0;
	num = (*p)->int_val;
	len = len_nbr(num);
//	trans = ft_strnew(len_nbr(num) * 2);
//	len = transform(num, 10, '0', trans) + 1;
	str = ft_strnew(len + (*p)->width + (*p)->precision + (*p)->space + 1);
	if (!str)
		return (1);
	
	if ((*p)->minus)
	{
		if (num < 0)
		{
			str[i++] = '-';
			num = num * (-1);
		}
		else
		{
			len--;
			if ((*p)->plus)
				str[i++] = '+';
			else if ((*p)->space)	// FLAG space (_)
				str[i++] = ' ';
			else
				len++;
		}
		i += for_precision(p, len, &str[i]);
		if ((*p)->zero)							// FLAG 0
			i += simvol_out(p, len, '0', &str[i]);
		ft_strcpy(&str[i], ft_itoa(num));
		i += len;
		i += simvol_out(p, len, ' ', &str[i]);
	}
	else
	{
		if (!(*p)->zero)
			i += ((*p)->plus || (*p)->space) ?
				simvol_out(p, len - 1, ' ', &str[i]) :
				simvol_out(p, len, ' ', &str[i]);
		if (num < 0)
		{
			str[i++] = '-';
			num = num * (-1);
		}
		else
		{
			len--;
			if ((*p)->plus)
				str[i++] = '+';
			else if ((*p)->space)	// FLAG space (_)
				str[i++] = ' ';
			else
				len++;
		}
		i += for_precision(p, len, &str[i]);
		if ((*p)->zero)							// FLAG 0
			i += simvol_out(p, len, '0', &str[i]);
		ft_strcpy(&str[i], ft_itoa(num));
		i += len;
	}
	
	
	/*if ((*p)->plus && num > 0)				// FLAG +
		str[i++] = '+';
	if (num < 0)
	{
		str[i++] = '-';
		num = num * (-1);
	}
	else if ((*p)->space && !(*p)->plus)	// FLAG space (_)
		str[i++] = ' ';
	i += for_precision(p, len, &str[i]);
	if ((*p)->zero)							// FLAG 0
		i += simvol_out(p, len, '0', &str[i]);
	if ((*p)->width > len && !(*p)->minus)
		i += simvol_out(p, len, ' ', &str[i]);
	ft_strcpy(&str[i], ft_itoa(num));
	if ((*p)->minus)						// FLAG -
		i += simvol_out(p, len, ' ', &str[i]);*/
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
	unsigned int	num;
	int				len;
	char	*str;
	int		i;

	i = 0;
	num = (*p)->uint_val; //va_arg((*p)->ap, unsigned int);
	len = len_nbr(num);
	str = ft_strnew(len + (*p)->width + (*p)->precision + (*p)->space + 1);
	if (!str)
		return (1);
//	if ((*p)->plus && num > 0)				// FLAG +
//		write(1, "+", 1);
	/*if (num < 0)
	{
		write(1, "-", 1);
		num = num * (-1);
	}
	else */
	if ((*p)->space && !(*p)->plus)	// FLAG space (_)
		str[i++] = ' '; //write(1, " ", 1);
	i += for_precision(p, len, &str[i]);
	if ((*p)->zero)							// FLAG 0
		i += simvol_out(p, len, '0', &str[i]);
	if ((*p)->width > len && !(*p)->minus)
		i += simvol_out(p, len, ' ', &str[i]);
	ft_strcpy(&str[i], ft_itoa(num));
	if ((*p)->minus)						// FLAG -
		i += simvol_out(p, len, ' ', &str[i]);
	
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	return (0);
}

// integer '8' unsigned
int		ft_o(t_printf **p)
{
	int		num;
	char	*str;
	char	*trans;
	int		len;
	int		i;

	i = 0;
	num = (*p)->int_val; //va_arg((*p)->ap, int);
	if (num < 0)
		return (1);
	trans = ft_strnew(len_nbr(num) * 2);
	str = ft_strnew(len_nbr(num) + (*p)->width + (*p)->precision + (*p)->space + 2);
	if (!str)
		return (1);
	len = transform(num, 8, '0', trans) + 1;
	if ((*p)->hash)
		len++;
	i += for_precision(p, len, &str[i]);
	if ((*p)->zero)							// FLAG 0
		i += simvol_out(p, len, '0', &str[i]);
	if ((*p)->width > len && !(*p)->minus)
		i += simvol_out(p, len, ' ', &str[i]);
	if ((*p)->hash)
	{
		str[i++] = '0'; //write(1, "0", 1);
		len--;
	}
	ft_strcpy(&str[i], trans); //write(1, str, len);
	if ((*p)->minus)						// FLAG -
		i += simvol_out(p, len, ' ', &str[i]);
	if ((*p)->hash)
		len--;
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	free(trans);
	return (0);
}

int		ft_x_universe(t_printf **p, char c)
{
	int		num;
	char	*str;
	char	*trans;
	int		len;
	int		i;

	i = 0;
	num = (*p)->int_val; //va_arg((*p)->ap, int);
	if (num < 0)
		return (1);
	trans = ft_strnew(len_nbr(num) * 2);
	str = ft_strnew(len_nbr(num) + (*p)->width + (*p)->precision + (*p)->space + 10);
	if (!str)
		return (1);
	len = transform(num, 16, c, trans) + 1;
	if ((*p)->hash)
		len += 2;
	i += for_precision(p, len, &str[i]);
	if ((*p)->zero)							// FLAG 0
		i += simvol_out(p, len, '0', &str[i]);
	if ((*p)->width > len && !(*p)->minus)
		i += simvol_out(p, len, ' ', &str[i]);
	if ((*p)->hash)
	{
		str[i++] = '0'; //write(1, "0x", 2);
		len -= 2;
	}
	ft_strcpy(&str[i], trans); //write(1, str, len);
	if ((*p)->minus)						// FLAG -
		i += simvol_out(p, len, ' ', &str[i]);
	if ((*p)->hash)
		len--;
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