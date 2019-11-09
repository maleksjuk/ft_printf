/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:31:12 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/09 19:50:19 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include "libft/includes/libft.h"

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

int		ft_d();
int		ft_i();
int		ft_u();

int		ft_o(int num)
{
	//int		num;
	char	*str;

	//(*p)->width;
	//num = (*p)->arg;
	str = transform(num, 8, '0');
	printf("%s\n", str);
	return (0);
}

int		ft_x(int num)
{
	//int		num;
	char	*str;

	//num = (*p)->arg;
	str = transform(num, 16, 'a');
	printf("%s\n", str);
	return (0);	
}

int		ft_X(int num)
{
	//int		num;
	char	*str;

	//num = (*p)->arg;
	str = transform(num, 16, 'A');
	printf("%s\n", str);
	return (0);
}

int		main()
{
	ft_o(12);
	ft_x(12);
	return (0);
}