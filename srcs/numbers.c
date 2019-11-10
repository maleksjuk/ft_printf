/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:31:12 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/10 15:13:02 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
//#include "libft/includes/libft.h"

char	*transform(int num, int system, char dec)
{
	char	c;
	char	*str;

	if (num < system)
	{
		c = num + dec;
		if (num > 9)
			c -= 10;
		//write(1, &c, 1);
		return (ft_strdup(&c));
	}
	else
	{
		str = transform(num / system, system, dec);
		c = num % system + dec;
		if (num % system > 9)
			c -= 10;
		//write(1, &c, 1);
		return (ft_strjoin(str, &c));
	}
}

// integer '10' signed
int		ft_d(t_printf **p)
{
	int	num;

	// prepare number to type
	num = va_arg((*p)->ap, int);
	// prepare flags to write
	// write chars
	printf("%i\n", num);
	return (0);
}

// integer '10' signed
int		ft_i(t_printf **p)
{
	int	num;

	// prepare number to type
	num = va_arg((*p)->ap, int);
	// prepare flags to write
	// write chars
	printf("%i\n", num);
	return (0);
}

// integer '10' unsigned
int		ft_u(t_printf **p)
{
	int	num;

	// prepare number to type
	num = va_arg((*p)->ap, int);
	// prepare flags to write
	// write chars
	printf("%i\n", num);
	return (0);
}

// integer '8' unsigned
int		ft_o(t_printf **p)
{
	int		num;
	char	*str;

	//(*p)->width;
	num = va_arg((*p)->ap, int);
	str = transform(num, 8, '0');
	printf("%s\n", str);
	return (0);
}

// integer '16' undigned 0123456789abcdef
int		ft_x(t_printf **p)
{
	int		num;
	char	*str;

	num = va_arg((*p)->ap, int);
	str = transform(num, 16, 'a');
	printf("%s\n", str);
	return (0);	
}

// integer '16' unsigned 0123456789ABCDEF
int		ft_X(t_printf **p)
{
	int		num;
	char	*str;

	num = va_arg((*p)->ap, int);
	str = transform(num, 16, 'A');
	printf("%s\n", str);
	return (0);
}

/*int		main()
{
	ft_i(12);
	return (0);
}*/