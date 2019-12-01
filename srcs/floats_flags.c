/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:27:45 by obanshee          #+#    #+#             */
/*   Updated: 2019/12/01 20:50:18 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	f_minus(t_printf **p, long double *num, char *str, int tab[4])
{
	int	help;

	help = tab[0] + (*p)->precision;
	if ((*p)->precision > 0 || (((*p)->hash) && (*p)->precision == 0))
		help++;
	if ((*num < 0 || 1 / (*num) == 1 / -0.0) && ++help)
	{
		str[tab[2]++] = '-';
		(*num) *= -1;
	}
	else if ((*p)->plus && num >= 0 && ++help)
		str[tab[2]++] = '+';
	else if ((*p)->space && num >= 0 && ++help)
		str[tab[2]++] = ' ';
	ft_left_part(num, &str, &tab[2], p);
	tab[2] += simvol_out(p, help, ' ', &str[help]);
	return (tab[2]);
}

int	f_zero(t_printf **p, long double *num, char *str, int tab[4])
{
	int	help;

	help = tab[0] + (*p)->precision + tab[3];
	if (*num < 0 || 1 / (*num) == 1 / -0.0)
	{
		str[tab[2]++] = '-';
		(*num) *= -1;
	}
	else if ((*p)->plus && num >= 0)
		str[tab[2]++] = '+';
	else if ((*p)->space)
		str[tab[2]++] = ' ';
	if ((*p)->precision > 0 || (((*p)->hash) && (*p)->precision == 0))
		help++;
	if ((*p)->hash)
		str[tab[2]++] = '0';
	tab[2] += simvol_out(p, help, '0', &str[tab[2]]);
	return (tab[2]);
}

int	f_def(t_printf **p, long double *num, char *str, int tab[4])
{
	int	help;

	help = tab[0] + (*p)->precision + tab[3];
	if ((*p)->precision > 0)
		help++;
	tab[2] += simvol_out(p, help, ' ', &str[tab[2]]);
	if (*num < 0 || 1 / (*num) == 1 / -0.0)
	{
		str[tab[2]++] = '-';
		(*num) *= -1;
	}
	else if ((*p)->plus && num >= 0)
		str[tab[2]++] = '+';
	else if ((*p)->space && num >= 0)
		str[tab[2]++] = ' ';
	return (tab[2]);
}
