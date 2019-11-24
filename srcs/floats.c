/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:04:59 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/24 15:03:03 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

double	ft_modulo(double num)
{
	double modulo;

	modulo = 1;
	while ((int)(num /= 10) != 0)
		modulo *= 10;
	return (modulo);
}

int		ft_nine(char **str, int *i, double num, int precision)
{
	int j;

	num *= 10;
	j = 0;
	while (j++ < precision)
	{
		if (num < 9)
			return (0);
		num = (num - (int)num) * 10;
	}
	if (num <= 5)
		return (0);
	j = 0;
	while (j++ < precision)
		(*str)[(*i)++] = '0';
	(*str)[(*i)] = '\0';
	return (1);
}

void	ft_right_part(char **str, int *i, double num, int precision)
{
	int		j;
	double	tmp;

	num *= 10;
	j = 0;
	while (j++ < precision)
	{
		if (precision - j == 0)
		{
			tmp = (int)((num - (int)num) * 10);
			if (tmp > 5)
				num += 1;
		}
		if ((int)num == 0)
		{
			(*str)[(*i)++] = '0';
			num *= 10;
			continue ;
		}
		(*str)[(*i)++] = (char)((int)num + 48);
		num = (num - (int)num) * 10;
	}
	(*str)[(*i)] = '\0';
}

int		ft_check_rounding(double num, intmax_t *x, int precision)
{
	int i;

	i = 0;
	num *= 10;
	if (precision == 0)
		(*x)++;
	else if ((int)num == 9)
	{
		while (i < precision)
		{
			if (num >= 9)
				num = (num - (int)(num)) * 10;
			else
				break ;
			i++;
		}
		if (num > 5 && i == precision)
			(*x)++;
	}
	return (0);
}

void	ft_left_part(double *num, char **str, int *i, t_printf **p)
{
	intmax_t	x;
	double		modulo;
	intmax_t	modulo_tmp;

	x = 0;
	modulo = ft_modulo(*num);
	modulo_tmp = (intmax_t)modulo;
	while ((int)*num != 0)
	{
		x = x + ((intmax_t)(*num / modulo)) * modulo;
		*num -= (int)(*num / modulo) * modulo;
		modulo /= 10;
		if (modulo < 1 && (*num * 10) > 5)
			ft_check_rounding(*num, &x, (*p)->precision);
	}
	while (modulo_tmp != 0)
	{
		(*str)[(*i)++] = (char)(x / modulo_tmp) + 48;
		x -= (x / modulo_tmp) * modulo_tmp;
		modulo_tmp /= 10;
	}
}

int		ft_infinity(t_printf **p, double num)
{
	if (num == 1 / -0.0)
		(*p)->final_str = ((*p)->uppercase == 1) ?
		ft_strjoin((*p)->final_str, "-Inf") :
			ft_strjoin((*p)->final_str, "-inf");
	else if (num == 1 / 0.0)
		(*p)->final_str = ((*p)->uppercase == 1) ?
		ft_strjoin((*p)->final_str, "Inf") :
			ft_strjoin((*p)->final_str, "inf");
	else if (num != num)
		(*p)->final_str = ((*p)->uppercase == 1) ?
		ft_strjoin((*p)->final_str, "Nan") :
			ft_strjoin((*p)->final_str, "nan");
	else
		return (0);
	return (1);
}

int		ft_f(t_printf **p)
{
	int		len;
	int		i;
	char	*str;
	double	num;

	i = 0;
	num = (*p)->double_val;
	if (ft_infinity(p, num))
		return (1);
	len = len_nbr((intmax_t)num);
	if ((*p)->precision == -1)
		(*p)->precision = 6;
	str = ft_strnew(len + (*p)->width + (*p)->precision + (*p)->space + 1);
	if (!str)
		return (1);
	if ((*p)->plus && num > 0)
		str[i++] = '+';
	if (num < 0 || 1 / (-0.0) == 1 / num)
	{
		str[i++] = '-';
		num = num * (-1);
	}
	else if ((*p)->space && !(*p)->plus)
		str[i++] = ' ';
	ft_left_part(&num, &str, &i, p);
	if ((*p)->precision != 0)
		str[i++] = '.';
	if (!(ft_nine(&str, &i, num, (*p)->precision)))
		ft_right_part(&str, &i, num, (*p)->precision);
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	return (0);
}
