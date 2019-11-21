/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:05:17 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/21 18:51:52 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	ft_search_type(t_printf **p, int i)
{
	if ((*p)->format[i] != '\0' &&
		ft_strchr((*p)->spec_mask, (*p)->format[i]))
		(*p)->type = (*p)->format[i];
	return (++i);
}

int 	ft_search_spec_2(t_printf **p, int i)
{
	char *tmp1;
	char *tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (!(*p)->final_str)
	{
		if (!((*p)->final_str = (char *)malloc(sizeof((*p)->final_str) * (i + 1))))
			return (-1);
		(*p)->final_str[i] = '\0';
		(*p)->final_str = ft_strncpy((*p)->final_str, (*p)->format, i);
	}
	else
	{
		if (!(tmp1 = (char *)malloc(sizeof(tmp1) * (i + 1))))
			return (-1);
		tmp1[i] = '\0';
		tmp1 = ft_strncpy(tmp1, (*p)->format, i);
		tmp2 = (*p)->final_str;
		(*p)->final_str = ft_strjoin((*p)->final_str, tmp1);
		free(tmp1);
		free(tmp2);
	}
	return (0);
}

int 	ft_search_spec_1(t_printf **p, int i)
{
	if ((*p)->final_str)
	{
		(*p)->format = (*p)->format + (*p)->index;
		if (i == -1)
			i = 1;
		else
			i = 0;
	}
	while (((*p)->format[i]) != '\0' && ((*p)->format[i]) != '%')
		i++;
	if (ft_search_spec_2(p, i) == -1)
		return (-1);
	if ((*p)->format[i] == '\0')
		return (-1);
	i++;
	if ((*p)->format[i] == '%')
	{
		(*p)->index = i;
		i = ft_search_spec_1(p, -1);
	}
	return (i);
}

int 	ft_choose_type(t_printf **p)
{
	int i;

	i = -1;
	int (*ft_type[10])(t_printf**) = {ft_d, ft_i, ft_o, ft_u, ft_x, ft_X, ft_c, ft_s, ft_f, ft_p};
	if ((*p)->type == 0)
	{
		ft_type[6](p);
		return (0);
	}
	while ((*p)->spec_mask[++i])
		if ((*p)->spec_mask[i] == (*p)->type)
			break;
	if (i < 10)
		ft_type[i](p);
	return (0);
}