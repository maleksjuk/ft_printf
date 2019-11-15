#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

#include <stdio.h>

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
	intmax_t			int_val;
	uintmax_t			uint_val;
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

// format.c
int		transform(int num, int system, char dec, char *str);
int		len_nbr(int num);
void	simvol_out(t_printf **p, int len, char c, char *str);
void	for_precision(t_printf **p, int len);

// numbers.c
//char	*transform(int num, int system, char dec);
int		len_nbr(int num);
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

#endif