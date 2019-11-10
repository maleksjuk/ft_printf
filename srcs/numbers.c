/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:31:12 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/10 19:16:07 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// transform int from '10' to 'X' system
int		transform(int num, int system, char dec, char *str)
{
	char	c;
	int		i;

	if (num < system)
	{
		c = num + dec;
		if (num > 9)
			c -= 10;
		str[0] = c;
		return (0);
	}
	else
	{
		i = transform(num / system, system, dec, str) + 1;
		c = num % system + dec;
		if (num % system > 9)
			c -= 10;
		str[i] = c;
		return (i);
	}
}

// length of number to define width
int		len_nbr(int num)
{
	int	len;

	len = 1;
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

void	simvol_out(t_printf **p, int len, char c)
{
	while ((*p)->width > len)
	{
		write(1, &c, 1);
		((*p)->width)--;
	}
}

void	for_precision(t_printf **p, int len)
{
	while ((*p)->precision > len)
	{
		write(1, "0", 1);
		((*p)->precision)--;
		if ((*p)->width > 0)
			((*p)->width)--;
	}
}

// integer '10' signed; FLAGS 0+-_
int		ft_d(t_printf **p)
{
	int	num;
	int	len;

	num = va_arg((*p)->ap, int);
	len = len_nbr(num);
	if ((*p)->plus && num > 0)				// FLAG +
		write(1, "+", 1);
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * (-1);
	}
	else if ((*p)->space && !(*p)->plus)	// FLAG space (_)
		write(1, " ", 1);
	for_precision(p, len);
	if ((*p)->zero)							// FLAG 0
		simvol_out(p, len, '0');
	if ((*p)->width > len && !(*p)->minus)
		simvol_out(p, len, ' ');
	ft_putnbr(num);
	if ((*p)->minus)						// FLAG -
		simvol_out(p, len, ' ');
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

	num = va_arg((*p)->ap, unsigned int);
	printf("%i\n", num);
	return (0);
}

// integer '8' unsigned
int		ft_o(t_printf **p)
{
	int		num;
	char	*str;
	int		len;

	num = va_arg((*p)->ap, int);
	if (num < 0)
		return (1);
	str = ft_strnew(len_nbr(num) * 2);
	if (!str)
		return (1);
	len = transform(num, 8, '0', str);

	if ((*p)->hash)
		len++;
	for_precision(p, len);
	if ((*p)->zero)							// FLAG 0
		simvol_out(p, len, '0');
	if ((*p)->width > len && !(*p)->minus)
		simvol_out(p, len, ' ');
	if ((*p)->hash)
		write(1, "#", 1);
	ft_putnbr(num);
	if ((*p)->minus)						// FLAG -
		simvol_out(p, len, ' ');
	if ((*p)->hash)
		len--;
	write(1, str, len + 1);
	free(str);
	return (0);
}

// integer '16' undigned 0123456789abcdef
int		ft_x(t_printf **p)
{
	int		num;
	char	*str;
	int		len;

	num = va_arg((*p)->ap, int);
	str = ft_strnew(len_nbr(num) * 2);
	if (!str)
		exit(1);
	len = transform(num, 16, 'a', str);
	write(1, str, len + 1);
	free(str);
	return (0);	
}

// integer '16' unsigned 0123456789ABCDEF
int		ft_X(t_printf **p)
{
	int		num;
	char	*str;
	int		len;

	num = va_arg((*p)->ap, int);
	str = ft_strnew(len_nbr(num) * 2);
	if (!str)
		return (1);
	len = transform(num, 16, 'A', str);
	write(1, str, len + 1);
	free(str);
	return (0);
}