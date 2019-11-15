/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:51:44 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/15 20:16:10 by obanshee         ###   ########.fr       */
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
		if (num > 9)
			c = num / 10 + dec;
		else
			c = num + '0';
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

void	simvol_out(t_printf **p, int len, char c, char *str)
{
	int	i;

	i = 0;
	while ((*p)->width > len)
	{
		str[i++] = c; //write(1, &c, 1);
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
