/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:30:22 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/24 19:02:08 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	d_minus(t_printf **p, intmax_t num, char *str, int tab[4],
				char *num_str)
{
	if (num < 0)
	{
		str[tab[2]++] = '-';
		num *= -1;
	}
	else if ((*p)->plus && num >= 0)
		str[tab[2]++] = '+';
	else if ((*p)->space && num >= 0)
		str[tab[2]++] = ' ';
	tab[2] += for_precision(p, tab[0] - tab[3], &str[tab[2]]);
	ft_strcpy(&str[tab[2]], num_str);
	if (tab[3])
		tab[2]--;
	tab[2] += tab[0];
	tab[2] += simvol_out(p, tab[0], ' ', &str[tab[2]]);
}

void	d_zero(t_printf **p, intmax_t num, char *str, int tab[4], char *num_str)
{
	if (num < 0)
	{
		str[tab[2]++] = '-';
		num *= -1;
	}
	else if ((*p)->plus && num >= 0)
		str[tab[2]++] = '+';
	else if ((*p)->space)
		str[tab[2]++] = ' ';
	tab[2] += for_precision(p, tab[0] - tab[3], &str[tab[2]]);
	tab[2] += simvol_out(p, tab[0], '0', &str[tab[2]]);
	ft_strcpy(&str[tab[2]], num_str);
}

void	d_def(t_printf **p, intmax_t num, char *str, int tab[4], char *num_str)
{
	int	help;

	help = tab[0] + (*p)->precision - tab[0] + tab[3];
	if ((*p)->precision > 0)
		tab[2] += simvol_out(p, help, ' ', &str[tab[2]]);
	else
		tab[2] += simvol_out(p, tab[0], ' ', &str[tab[2]]);
	if (num < 0)
	{
		str[tab[2]++] = '-';
		num *= -1;
	}
	else if ((*p)->plus && num >= 0)
		str[tab[2]++] = '+';
	else if ((*p)->space && num >= 0)
		str[tab[2]++] = ' ';
	if (num == 0)
		tab[2] += for_precision(p, tab[0] - tab[3] + 1, &str[tab[2]]);
	else
		tab[2] += for_precision(p, tab[0] - tab[3], &str[tab[2]]);
	ft_strcpy(&str[tab[2]], num_str);
}

char	*ft_num_str(t_printf **p, intmax_t num, int tab[4])
{
	char	*num_str;

	if (num / 10 == MAX_INT && num % 10 == -8)
	{
		num_str = ft_strnew(22);
		if (!num_str)
			return (NULL);
		ft_strcpy(num_str, "9223372036854775808\0");
	}
	else
		num_str = ft_itoa(num);
	if (num_str[0] == '-')
	{
		num_str[0] = '\0';
		num_str = &num_str[1];
	}
	if (num == 0 && (*p)->precision == 0)
	{
		num_str = "\0";
		tab[0] = 0;
	}
	return (num_str);
}

int		ft_d(t_printf **p)
{
	intmax_t	num;
	char		*str;
	char		*num_str;
	int			tab[4];

	tab[2] = 0;
	tab[3] = 0;
	num = (*p)->int_val;
	if (num < 0 || (*p)->plus || (*p)->space)
		tab[3] = 1;
	tab[0] = len_nbr(num);
	if (tab[3])
		tab[0]++;
	tab[1] = max_val(tab[0], max_val((*p)->precision, (*p)->width)) + tab[3];
	str = ft_strnew(tab[1] + 1);
	if (!str)
		return (1);
	num_str = ft_num_str(p, num, tab);
	if ((*p)->minus)
		d_minus(p, num, str, tab, num_str);
	else if ((*p)->zero && (*p)->precision < 0)
		d_zero(p, num, str, tab, num_str);
	else
		d_def(p, num, str, tab, num_str);
	(*p)->final_str = ft_strjoin((*p)->final_str, str);
	free(str);
	if (num < 0)
		num_str--;
//	free(num_str);
	return (0);
}

int		ft_i(t_printf **p)
{
	return (ft_d(p));
}
