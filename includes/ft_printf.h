/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:04:26 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/19 19:04:45 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "../libft/includes/libft.h"

# include <stdio.h>

typedef struct			s_printf
{
	va_list				ap;
	char				*final_str;
	int					final_len;
	void 				*arg;
	int					index;
	int 				minus;
	int 				plus;
	int 				zero;
	int 				space;
	int 				hash;
	int 				width;
	int 				precision;
	long double 		double_val;
	intmax_t			int_val;
	uintmax_t			uint_val;
	char				*str_val;
	char				type;
	char				size;
	char				*format;
	char				*spec_mask;
	char				*size_mask;
}						t_printf;

// ft_printf.c
int		ft_printf(const char* format, ...);
int 	ft_construct(t_printf **p);
int 	ft_pars(t_printf **p);
int 	ft_search_spec(t_printf **p, int i);
void	ft_choose_value(t_printf **p);

// pars_1.c
int 	ft_pars(t_printf **p);

// pars_2.c
int 	ft_search_type(t_printf **p, int i);
int 	ft_search_spec_1(t_printf **p, int i);
int		ft_search_spec_2(t_printf **p, int i);
int 	ft_choose_type(t_printf **p);

// size.c
void	ft_choose_value(t_printf **p);

// format.c
int		transform(uintmax_t num, unsigned int system, char dec, char *str);
int		len_nbr(intmax_t num);
int		simvol_out(t_printf **p, int len, char c, char *str);
int		for_precision(t_printf **p, int len, char *str);

// numbers.c
int		ft_d(t_printf **p);
int		ft_i(t_printf **p);
int		ft_u(t_printf **p);
int		ft_o(t_printf **p);
int		ft_x(t_printf **p);
int		ft_X(t_printf **p);

// chars.c
int		ft_c(t_printf **p);
int		ft_s(t_printf **p);
int		ft_p(t_printf **p);

// floats.c
int 	ft_f(t_printf **p);

#endif