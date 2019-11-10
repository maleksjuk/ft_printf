#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

#include <stdio.h>

typedef struct			s_printf
{
	va_list				ap;
	void 				*arg;
	int 				width;
	int 				precision;
	char				type;
	char				*format;
	char				*spec_mask;
//	struct s_printf		*next;
}						t_printf;

// ft_printf.c
int		ft_printf(const char* format, ...);
int 	ft_construct(const char* format, t_printf **p);
int 	ft_pars(t_printf **p);
int 	ft_search_spec(t_printf **p, int i);

// numbers.c
char	*transform(int num, int system, char dec);
int		ft_d(t_printf **p);
int		ft_i(t_printf **p);
int		ft_u(t_printf **p);
int		ft_o(t_printf **p);
int		ft_x(t_printf **p);
int		ft_X(t_printf **p);

#endif