/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:09:55 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/15 20:15:40 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*int	ft_c(t_printf **p)
{
	char	c;

	c = (char)(*p)->int_val;
	if ((*p)->width > 1 && !(*p)->minus)
		simvol_out(p, 1, ' ');
	ft_putchar(c);
	if ((*p)->minus)
		simvol_out(p, 1, ' ');
	return (0);
}*/

int ft_s(t_printf **p);
int	ft_p(t_printf **p);