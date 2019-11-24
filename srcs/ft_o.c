/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:31:17 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/24 18:37:42 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	o_minus(t_printf **p, char *str, int tab[3], char *trans)
{
	if ((*p)->hash)
		str[tab[2]++] = '0';
	tab[2] += for_precision(p, tab[0] - (*p)->hash, &str[tab[2]]);
	ft_strcpy(&str[tab[2]], trans);
	if ((*p)->hash)
		tab[2] += tab[0] - 1;
	else
		tab[2] += tab[0];
	tab[2] += simvol_out(p, tab[0], ' ', &str[tab[2]]);
}

void	o_zero(t_printf **p, char *str, int tab[3], char *trans)
{
	if ((*p)->hash)
		str[tab[2]++] = '0';
	tab[2] += for_precision(p, tab[0], &str[tab[2]]);
	tab[2] += simvol_out(p, tab[0], '0', &str[tab[2]]);
	ft_strcpy(&str[tab[2]], trans);
}

void	o_default(t_printf **p, char *str, int tab[3], char *trans)
{
	int	help;

	help = tab[0] + (*p)->precision - tab[0];
	if ((*p)->precision > tab[0])
		tab[2] += simvol_out(p, help, ' ', &str[tab[2]]);
	else
		tab[2] += simvol_out(p, tab[0], ' ', &str[tab[2]]);
	if ((*p)->hash)
	{
		str[tab[2]++] = '0';
		tab[0]--;
	}
	tab[2] += for_precision(p, tab[0], &str[tab[2]]);
	ft_strcpy(&str[tab[2]], trans);
}

int		ft_o(t_printf **p)
{
	uintmax_t	num;
	char		*str;
	char		*trans;
	int			tab[3];

	tab[2] = 0;
	num = (*p)->uint_val;
	trans = ft_strnew(len_nbr(num) * 3);
	if (!trans)
		return (1);
	tab[0] = transform(num, 8, '0', trans) + 1;
	tab[1] = max_val(tab[0], max_val((*p)->precision, (*p)->width));
	str = ft_strnew(tab[1] + 10);
	if (!str)
		return (1);
	if ((*p)->precision > tab[0])
		(*p)->hash = 0;
	if (num == 0 && (*p)->precision == 0)
	{
		trans[0] = '\0';
		tab[0] = 0;
	}
	if ((*p)->hash)
		tab[0]++;
	if ((*p)->minus)
		o_minus(p, str, tab, trans);
	else if ((*p)->zero && (*p)->precision < 0)
		o_zero(p, str, tab, trans);
	else
		o_default(p, str, tab, trans);
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	//free(trans);
	return (0);
}
