#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

#include <stdio.h>

typedef struct			s_printf
{
	va_list				ap;
	char				type;
	char				*format;
	char				*spec_mask;
//	struct s_printf		*next;
}						t_printf;

#endif