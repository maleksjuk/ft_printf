/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:04:09 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/21 19:49:22 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	ft_final(t_printf **p)
{
	ft_putstr((*p)->final_str);
	(*p)->final_len = ft_strlen((*p)->final_str);
	free((*p)->final_str);
	free(*p);
	return (0);
}

int 	ft_construct(t_printf **p)
{
	(*p)->final_len = 0;
	(*p)->minus = 0;
	(*p)->plus = 0;
	(*p)->zero = 0;
	(*p)->hash = 0;
	(*p)->space = 0;
	(*p)->width = 0; 
	(*p)->precision = -1;
	(*p)->int_val = 0;
	(*p)->uint_val = 0;
	(*p)->type = 0;
	(*p)->size = 0;
	(*p)->spec_mask = "diouxXcsfp";
	(*p)->size_mask = "hl";
	return (0);
}

int		ft_printf(const char* format, ...)
{
	t_printf *p;

	if (!(p = (t_printf*)malloc(sizeof(*p))))
		return (-1);
	if (format[0] == '\0')
		return (0);
	va_start(p->ap, format);
	p->index = 0;
	p->final_str = ft_strnew(1);
	p->format = (char *)format;
	while (format[p->index] != '\0')
	{
		ft_construct(&p);
		if (ft_pars(&p) == -1)
			break ;
	}
	ft_final(&p);
	va_end(p->ap);
	return (p->final_len);
}

int		main(void)
{

//	ft_printf("This is test  0: |%#x|---|%5s|\n", 42, "%x");
//	ft_printf("This is test  0: |%#X|---|%5s|\n", 42, "%X");

//	ft_printf("%.1f\n", 46.5);
//	ft_printf("%.1f\n", 46.5);
//	ft_printf("%.0f\n", 46.5);
//	ft_printf("%.0f\n", 46.5);
//	ft_printf("%.10f\n", 12321.3293923499);
//	ft_printf("%.10f\n", 12321.3293923499);
//	ft_printf("%.10f\n", 29301.9876319200001);
//	ft_printf("%.10f\n", 29301.9876319200001);
//	ft_printf("%.3f\n", 1002.929);
//	ft_printf("%.3f\n", 1002.929);
//	ft_printf("%.10f\n", 87381298.309800499);
//	ft_printf("%.10f\n", 87381298.309800499);
//	ft_printf("%.10f\n", 1.1111119);
//	ft_printf("%.10f\n", 1.1111119);
//	ft_printf("%.10f\n", 1002.99999125367);
//	ft_printf("%.10f\n", 1002.99999125367);

//	int		a, b, e;
//	char	c;
//	char	*str = "string";

	// a = 12;
	// b = -3;
	// c = 'M';
	// e = 2;

/*	ft_printf("NO_STANDART TYPE d (i):\nnumber > 0\n");
	ft_printf("This is test  0: |%3.*d|---|%5s|\n", e, a, "%3.*d");
	ft_printf("This is test  1: |%+3.*d|---|%5s|\n", e, a, "%+3.*d");
	ft_printf("This is test  2: |%-3.*d|---|%5s|\n", e, a, "%-3.*d");
	ft_printf("This is test  3: |% 3.*d|---|%5s|\n", e, a, "% 3.*d");
	ft_printf("This is test  4: |%03.*d|---|%5s|\n", e, a, "%03.*d");
	ft_printf("This is test  5: |% +3.*d|---|%5s|\n", e, a, "% +3.*d");
	ft_printf("This is test  6: |% -3.*d|---|%5s|\n", e, a, "% -3.*d");
	ft_printf("This is test  7: |%+-3.*d|---|%5s|\n", e, a, "%+-3.*d");
	ft_printf("This is test  8: |%0-3.*d|---|%5s|\n", e, a, "%0-3.*d");
	ft_printf("This is test  9: |%0+3.*d|---|%5s|\n", e, a, "%0+3.*d");
	ft_printf("This is test 10: |% 03.*d|---|%5s|\n", e, a, "% 03.*d");
	ft_printf("This is test 11: |% -3.*d|---|%5s|\n\n", e, a, "% -3.*d");

	ft_printf("number < 0\n");
	ft_printf("This is test  0: |%3.*d|---|%5s|\n", e, b, "%3.*d");
	ft_printf("This is test  1: |%+3.*d|---|%5s|\n", e, b, "%+3.*d");
	ft_printf("This is test  2: |%-3.*d|---|%5s|\n", e, b, "%-3.*d");
	ft_printf("This is test  3: |% 3.*d|---|%5s|\n", e, b, "% 3.*d");
	ft_printf("This is test  4: |%03.*d|---|%5s|\n", e, b, "%03.*d");
	ft_printf("This is test  5: |% +3.*d|---|%5s|\n", e, b, "% +3.*d");
	ft_printf("This is test  6: |% -3.*d|---|%5s|\n", e, b, "% -3.*d");
	ft_printf("This is test  7: |%+-3.*d|---|%5s|\n", e, b, "%+-3.*d");
	ft_printf("This is test  8: |%0-3.*d|---|%5s|\n", e, b, "%0-3.*d");
	ft_printf("This is test  9: |%0+3.*d|---|%5s|\n", e, b, "%0+3.*d");
	ft_printf("This is test 10: |% 03.*d|---|%5s|\n", e, b, "% 03.*d");
	ft_printf("This is test 11: |% -3.*d|---|%5s|\n\n", e, b, "% -3.*d");

	ft_printf("NO_STANDART TYPE u:\nnumber > 0\n");
	ft_printf("This is test  0: |%3.*u|---|%5s|\n", e, a, "%3.*u");
	ft_printf("This is test  1: |%+3.*u|---|%5s|\n", e, a, "%+3.*u");
	ft_printf("This is test  2: |%-3.*u|---|%5s|\n", e, a, "%-3.*u");
	ft_printf("This is test  3: |% 3.*u|---|%5s|\n", e, a, "% 3.*u");
	ft_printf("This is test  4: |%03.*u|---|%5s|\n", e, a, "%03.*u");
	ft_printf("This is test  5: |% +3.*u|---|%5s|\n", e, a, "% +3.*u");
	ft_printf("This is test  6: |% -3.*u|---|%5s|\n", e, a, "% -3.*u");
	ft_printf("This is test  7: |%+-3.*u|---|%5s|\n", e, a, "%+-3.*u");
	ft_printf("This is test  8: |%0-3.*u|---|%5s|\n", e, a, "%0-3.*u");
	ft_printf("This is test  9: |%0+3.*u|---|%5s|\n", e, a, "%0+3.*u");
	ft_printf("This is test 10: |% 03.*u|---|%5s|\n", e, a, "% 03.*u");
	ft_printf("This is test 11: |% -3.*u|---|%5s|\n\n", e, a, "% -3.*u");

	ft_printf("number < 0\n");
	ft_printf("This is test  1: |%3.*u|---|%5s|\n", e, b, "%3.*u");
	ft_printf("This is test  1: |%+3.*u|---|%5s|\n", e, b, "%+3.*u");
	ft_printf("This is test  2: |%-3.*u|---|%5s|\n", e, b, "%-3.*u");
	ft_printf("This is test  3: |% 3.*u|---|%5s|\n", e, b, "% 3.*u");
	ft_printf("This is test  4: |%03.*u|---|%5s|\n", e, b, "%03.*u");
	ft_printf("This is test  5: |% +3.*u|---|%5s|\n", e, b, "% +3.*u");
	ft_printf("This is test  6: |% -3.*u|---|%5s|\n", e, b, "% -3.*u");
	ft_printf("This is test  7: |%+-3.*u|---|%5s|\n", e, b, "%+-3.*u");
	ft_printf("This is test  8: |%0-3.*u|---|%5s|\n", e, b, "%0-3.*u");
	ft_printf("This is test  9: |%0+3.*u|---|%5s|\n", e, b, "%0+3.*u");
	ft_printf("This is test 10: |% 03.*u|---|%5s|\n", e, b, "% 03.*u");
	ft_printf("This is test 11: |% -3.*u|---|%5s|\n\n", e, b, "% -3.*u");

	ft_printf("NO_STANDART TYPE o:\nnumber > 0\n");
	ft_printf("This is test  0: |%3.*o|---|%5s|\n", e, a, "%3.*o");
	ft_printf("This is test  1: |%+3.*o|---|%5s|\n", e, a, "%+3.*o");
	ft_printf("This is test  2: |%-3.*o|---|%5s|\n", e, a, "%-3.*o");
	ft_printf("This is test  3: |% 3.*o|---|%5s|\n", e, a, "% 3.*o");
	ft_printf("This is test  4: |%#3.*o|---|%5s|\n", e, a, "%#3.*o");
	ft_printf("This is test  5: |%03.*o|---|%5s|\n", e, a, "%03.*o");
	ft_printf("This is test  6: |%#+3.*o|---|%5s|\n", e, a, "%#+3.*o");
	ft_printf("This is test  7: |%#-3.*o|---|%5s|\n", e, a, "%#-3.*o");
	ft_printf("This is test  8: |%#03.*o|---|%5s|\n", e, a, "%#03.*o");
	ft_printf("This is test  9: |% #3.*o|---|%5s|\n", e, a, "% #3.*o");
	ft_printf("This is test 10: |%+-3.*o|---|%5s|\n", e, a, "%+-3.*o");
	ft_printf("This is test 11: |%+03.*o|---|%5s|\n", e, a, "%+03.*o");
	ft_printf("This is test 12: |% +3.*o|---|%5s|\n", e, a, "% +3.*o");
	ft_printf("This is test 13: |%-03.*o|---|%5s|\n", e, a, "%-03.*o");
	ft_printf("This is test 14: |% -3.*o|---|%5s|\n", e, a, "% -3.*o");
	ft_printf("This is test 15: |% 03.*o|---|%5s|\n\n", e, a, "% 03.*o");

	ft_printf("number < 0\n");
	ft_printf("This is test  0: |%3.*o|---|%5s|\n", e, b, "%3.*o");
	ft_printf("This is test  1: |%+3.*o|---|%5s|\n", e, b, "%+3.*o");
	ft_printf("This is test  2: |%-3.*o|---|%5s|\n", e, b, "%-3.*o");
	ft_printf("This is test  3: |% 3.*o|---|%5s|\n", e, b, "% 3.*o");
	ft_printf("This is test  4: |%#3.*o|---|%5s|\n", e, b, "%#3.*o");
	ft_printf("This is test  5: |%03.*o|---|%5s|\n", e, b, "%03.*o");
	ft_printf("This is test  6: |%#+3.*o|---|%5s|\n", e, b, "%#+3.*o");
	ft_printf("This is test  7: |%#-3.*o|---|%5s|\n", e, b, "%#-3.*o");
	ft_printf("This is test  8: |%#03.*o|---|%5s|\n", e, b, "%#03.*o");
	ft_printf("This is test  9: |% #3.*o|---|%5s|\n", e, b, "% #3.*o");
	ft_printf("This is test 10: |%+-3.*o|---|%5s|\n", e, b, "%+-3.*o");
	ft_printf("This is test 11: |%+03.*o|---|%5s|\n", e, b, "%+03.*o");
	ft_printf("This is test 12: |% +3.*o|---|%5s|\n", e, b, "% +3.*o");
	ft_printf("This is test 13: |%-03.*o|---|%5s|\n", e, b, "%-03.*o");
	ft_printf("This is test 14: |% -3.*o|---|%5s|\n", e, b, "% -3.*o");
	ft_printf("This is test 15: |% 03.*o|---|%5s|\n\n", e, b, "% 03.*o");

	ft_printf("NO_STANDART TYPE x (X):\nnumber > 0\n");
	ft_printf("This is test  0: |%5.*x|---|%5s|\n", e, a, "%5.*x");
	ft_printf("This is test  1: |%+5.*x|---|%5s|\n", e, a, "%+5.*x");
	ft_printf("This is test  2: |%-5.*x|---|%5s|\n", e, a, "%-5.*x");
	ft_printf("This is test  3: |% 5.*x|---|%5s|\n", e, a, "% 5.*x");
	ft_printf("This is test  4: |%#5.*x|---|%5s|\n", e, a, "%#5.*x");
	ft_printf("This is test  5: |%05.*x|---|%5s|\n", e, a, "%05.*x");
	ft_printf("This is test  6: |%#+5.*x|---|%5s|\n", e, a, "%#+5.*x");
	ft_printf("This is test  7: |%#-5.*x|---|%5s|\n", e, a, "%#-5.*x");
	ft_printf("This is test  8: |%#05.*x|---|%5s|\n", e, a, "%#05.*x");
	ft_printf("This is test  9: |% #5.*x|---|%5s|\n", e, a, "% #5.*x");
	ft_printf("This is test 10: |%+-5.*x|---|%5s|\n", e, a, "%+-5.*x");
	ft_printf("This is test 11: |%+05.*x|---|%5s|\n", e, a, "%+05.*x");
	ft_printf("This is test 12: |% +5.*x|---|%5s|\n", e, a, "% +5.*x");
	ft_printf("This is test 13: |%-05.*x|---|%5s|\n", e, a, "%-05.*x");
	ft_printf("This is test 14: |% -5.*x|---|%5s|\n", e, a, "% -5.*x");
	ft_printf("This is test 15: |% 05.*x|---|%5s|\n\n", e, a, "% 05.*x");

	ft_printf("number < 0\n");
	ft_printf("This is test  0: |%5.*x|---|%5s|\n", e, b, "%5.*x");
	ft_printf("This is test  1: |%+5.*x|---|%5s|\n", e, b, "%+5.*x");
	ft_printf("This is test  2: |%-5.*x|---|%5s|\n", e, b, "%-5.*x");
	ft_printf("This is test  3: |% 5.*x|---|%5s|\n", e, b, "% 5.*x");
	ft_printf("This is test  4: |%#5.*x|---|%5s|\n", e, b, "%#5.*x");
	ft_printf("This is test  5: |%05.*x|---|%5s|\n", e, b, "%05.*x");
	ft_printf("This is test  6: |%#+5.*x|---|%5s|\n", e, b, "%#+5.*x");
	ft_printf("This is test  7: |%#-5.*x|---|%5s|\n", e, b, "%#-5.*x");
	ft_printf("This is test  8: |%#05.*x|---|%5s|\n", e, b, "%#05.*x");
	ft_printf("This is test  9: |% #5.*x|---|%5s|\n", e, b, "% #5.*x");
	ft_printf("This is test 10: |%+-5.*x|---|%5s|\n", e, b, "%+-5.*x");
	ft_printf("This is test 11: |%+05.*x|---|%5s|\n", e, b, "%+05.*x");
	ft_printf("This is test 12: |% +5.*x|---|%5s|\n", e, b, "% +5.*x");
	ft_printf("This is test 13: |%-05.*x|---|%5s|\n", e, b, "%-05.*x");
	ft_printf("This is test 14: |% -5.*x|---|%5s|\n", e, b, "% -5.*x");
	ft_printf("This is test 15: |% 05.*x|---|%5s|\n\n", e, b, "% 05.*x");

	ft_printf("NO_STANDART TYPE c:\n");
	ft_printf("This is test  0: |%5.*c|---|%5s|\n", e, c, "%5.*c");
	ft_printf("This is test  1: |%+5.*c|---|%5s|\n", e, c, "%+5.*c");
	ft_printf("This is test  2: |%-5.*c|---|%5s|\n", e, c, "%-5.*c");
	ft_printf("This is test  3: |% 5.*c|---|%5s|\n", e, c, "% 5.*c");
	ft_printf("This is test  4: |%#5.*c|---|%5s|\n", e, c, "%#5.*c");
	ft_printf("This is test  5: |%05.*c|---|%5s|\n", e, c, "%05.*c");
	ft_printf("This is test  6: |%#+5.*c|---|%5s|\n", e, c, "%#+5.*c");
	ft_printf("This is test  7: |%#-5.*c|---|%5s|\n", e, c, "%#-5.*c");
	ft_printf("This is test  8: |%#05.*c|---|%5s|\n", e, c, "%#05.*c");
	ft_printf("This is test  9: |% #5.*c|---|%5s|\n", e, c, "% #5.*c");
	ft_printf("This is test 10: |%+-5.*c|---|%5s|\n", e, c, "%+-5.*c");
	ft_printf("This is test 11: |%+05.*c|---|%5s|\n", e, c, "%+05.*c");
	ft_printf("This is test 12: |% +5.*c|---|%5s|\n", e, c, "% +5.*c");
	ft_printf("This is test 13: |%-05.*c|---|%5s|\n", e, c, "%-05.*c");
	ft_printf("This is test 14: |% -5.*c|---|%5s|\n", e, c, "% -5.*c");
	ft_printf("This is test 15: |% 05.*c|---|%5s|\n\n", e, c, "% 05.*c");

	ft_printf("NO_STANDART TYPE s:\n");
	ft_printf("This is test  0: |%5.*s|---|%5s|\n", e, str, "%5.*s");
	ft_printf("This is test  1: |%+5.*s|---|%5s|\n", e, str, "%+5.*s");
	ft_printf("This is test  2: |%-5.*s|---|%5s|\n", e, str, "%-5.*s");
	ft_printf("This is test  3: |% 5.*s|---|%5s|\n", e, str, "% 5.*s");
	ft_printf("This is test  4: |%#5.*s|---|%5s|\n", e, str, "%#5.*s");
	ft_printf("This is test  5: |%05.*s|---|%5s|\n", e, str, "%05.*s");
	ft_printf("This is test  6: |%#+5.*s|---|%5s|\n", e, str, "%#+5.*s");
	ft_printf("This is test  7: |%#-5.*s|---|%5s|\n", e, str, "%#-5.*s");
	ft_printf("This is test  8: |%#05.*s|---|%5s|\n", e, str, "%#05.*s");
	ft_printf("This is test  9: |% #5.*s|---|%5s|\n", e, str, "% #5.*s");
	ft_printf("This is test 10: |%+-5.*s|---|%5s|\n", e, str, "%+-5.*s");
	ft_printf("This is test 11: |%+05.*s|---|%5s|\n", e, str, "%+05.*s");
	ft_printf("This is test 12: |% +5.*s|---|%5s|\n", e, str, "% +5.*s");
	ft_printf("This is test 13: |%-05.*s|---|%5s|\n", e, str, "%-05.*s");
	ft_printf("This is test 14: |% -5.*s|---|%5s|\n", e, str, "% -5.*s");
	ft_printf("This is test 15: |% 05.*s|---|%5s|\n", e, str, "% 05.*s");
*/
/*	int	w = 10;
	int	p[2] = {10, 12};
	//int	p1 = 107;
	//int	*p = &p1;
	//uintmax_t p = 140734670944856; // 1477556824
	int	e = 5;

	ft_printf("NO_STANDART TYPE p:\n");
	ft_printf("This is test  0: |%*.*p|---|%5s|\n", w, e, p, "%5.*p");
	ft_printf("This is test  1: |%+*.*p|---|%5s|\n", w, e, p, "%+5.*p");
	ft_printf("This is test  2: |%-*.*p|---|%5s|\n", w, e, p, "%-5.*p");
	ft_printf("This is test  3: |% *.*p|---|%5s|\n", w, e, p, "% 5.*p");
	ft_printf("This is test  4: |%#*.*p|---|%5s|\n", w, e, p, "%#5.*p");
	ft_printf("This is test  5: |%0*.*p|---|%5s|\n", w, e, p, "%05.*p");
	ft_printf("This is test  6: |%#+*.*p|---|%5s|\n", w, e, p, "%#+5.*p");
	ft_printf("This is test  7: |%#-*.*p|---|%5s|\n", w, e, p, "%#-5.*p");
	ft_printf("This is test  8: |%#0*.*p|---|%5s|\n", w, e, p, "%#05.*p");
	ft_printf("This is test  9: |% #*.*p|---|%5s|\n", w, e, p, "% #5.*p");
	ft_printf("This is test 10: |%+-*.*p|---|%5s|\n", w, e, p, "%+-5.*p");
	ft_printf("This is test 11: |%+0*.*p|---|%5s|\n", w, e, p, "%+05.*p");
	ft_printf("This is test 12: |% +*.*p|---|%5s|\n", w, e, p, "% +5.*p");
	ft_printf("This is test 13: |%-0*.*p|---|%5s|\n", w, e, p, "%-05.*p");
	ft_printf("This is test 14: |% -*.*p|---|%5s|\n", w, e, p, "% -5.*p");
	ft_printf("This is test 15: |% 0*.*p|---|%5s|\n\n", w, e, p, "% 05.*p");

	ft_printf("NO_STANDART TYPE p:\n");
	ft_printf("This is test  0: |%*p|---|%5s|\n", w, p, "%*p");
	ft_printf("This is test  1: |%+*p|---|%5s|\n", w, p, "%+*p");
	ft_printf("This is test  2: |%-*p|---|%5s|\n", w, p, "%-*p");
	ft_printf("This is test  3: |% *p|---|%5s|\n", w, p, "% *p");
	ft_printf("This is test  4: |%#*p|---|%5s|\n", w, p, "%#*p");
	ft_printf("This is test  5: |%0*p|---|%5s|\n", w, p, "%0*p");
	ft_printf("This is test  6: |%#+*p|---|%5s|\n", w, p, "%#+*p");
	ft_printf("This is test  7: |%#-*p|---|%5s|\n", w, p, "%#-*p");
	ft_printf("This is test  8: |%#0*p|---|%5s|\n", w, p, "%#0*p");
	ft_printf("This is test  9: |% #*p|---|%5s|\n", w, p, "% #*p");
	ft_printf("This is test 10: |%+-*p|---|%5s|\n", w, p, "%+-*p");
	ft_printf("This is test 11: |%+0*p|---|%5s|\n", w, p, "%+0*p");
	ft_printf("This is test 12: |% +*p|---|%5s|\n", w, p, "% +*p");
	ft_printf("This is test 13: |%-0*p|---|%5s|\n", w, p, "%-0*p");
	ft_printf("This is test 14: |% -*p|---|%5s|\n", w, p, "% -*p");
	ft_printf("This is test 15: |% 0*p|---|%5s|\n\n", w, p, "% 0*p");

	ft_printf("NO_STANDART TYPE p:\n");
	ft_printf("This is test  0: |%p|---|%5s|\n", p, "%p");
	ft_printf("This is test  1: |%+p|---|%5s|\n", p, "%+p");
	ft_printf("This is test  2: |%-p|---|%5s|\n", p, "%-p");
	ft_printf("This is test  3: |% p|---|%5s|\n", p, "% p");
	ft_printf("This is test  4: |%#p|---|%5s|\n", p, "%#p");
	ft_printf("This is test  5: |%0p|---|%5s|\n", p, "%0p");
	ft_printf("This is test  6: |%#+p|---|%5s|\n", p, "%#+p");
	ft_printf("This is test  7: |%#-p|---|%5s|\n", p, "%#-p");
	ft_printf("This is test  8: |%#0p|---|%5s|\n", p, "%#0p");
	ft_printf("This is test  9: |% #p|---|%5s|\n", p, "% #p");
	ft_printf("This is test 10: |%+-p|---|%5s|\n", p, "%+-p");
	ft_printf("This is test 11: |%+0p|---|%5s|\n", p, "%+0p");
	ft_printf("This is test 12: |% +p|---|%5s|\n", p, "% +p");
	ft_printf("This is test 13: |%-0p|---|%5s|\n", p, "%-0p");
	ft_printf("This is test 14: |% -p|---|%5s|\n", p, "% -p");
	ft_printf("This is test 15: |% 0p|---|%5s|\n\n", p, "% 0p");

*/

 
	ft_printf("-->|");
	ft_printf("%s", "this is a string");
	ft_printf("|<--\n");
	ft_printf("-->|");
	ft_printf("%s ", "this is a string");
	ft_printf("|<--\n");
	ft_printf("-->|");
	ft_printf("%s  ", "this is a string");
	ft_printf("|<--\n");
	ft_printf("-->|");
	ft_printf("%5.2s is a string", "");
	ft_printf("|<--\n");
	ft_printf("-->|");
	ft_printf("%-10s is a string", "this");
	ft_printf("|<--\n");
	ft_printf("-->|");
	ft_printf("%-5.2s is a string", "");
	ft_printf("|<--\n");
	// ft_printf(">@moulitest: %s<\n", NULL);     
	// ft_printf(">%.2c<\n", NULL);          
	// ft_printf(">%s %s<\n", NULL, "string");    
	// ft_printf(">@moulitest: %c<\n", 0);    
	// ft_printf(">%2c<\n", 0);          
	// ft_printf(">null %c and text<\n", 0);  
	// ft_printf(">% c<\n", 0);  
	// ft_printf(">@moulitest: %.o %.0o<\n", 0, 0); 
	// ft_printf(">@moulitest: %5.o %5.0o<\n", 0, 0);
	// ft_printf(">@moulitest: %#.o %#.0o<\n", 0, 0);
	// ft_printf(">%d<\n", 2147483648);
	// ft_printf(">%d<\n", -2147483648);
	// ft_printf(">%+d<\n", 0);
	// ft_printf(">%ld<\n", -2147483648);
	// ft_printf(">%ld<\n", 2147483648); 
	// ft_printf(">%ld<\n", -2147483649);
	// ft_printf(">%lld<\n", 9223372036854775807); 
	// ft_printf(">%lld<\n", -9223372036854775808); 
	// ft_printf(">@moulitest: %.d %.0d<\n", 0, 0);
	// ft_printf(">@moulitest: %5.d %5.0dv\n", 0, 0);
	// ft_printf(">%u<\n", -1);         
	// ft_printf(">%u<\n", 4294967295); 
	// ft_printf(">%5u<\n", 4294967295);
	// ft_printf(">%15u<\n", 4294967295); 
	// ft_printf(">%-15u<\n", 4294967295); 
	// ft_printf(">%015u<\n", 4294967295); 
	// ft_printf(">% u<\n", 4294967295);
	// ft_printf(">%+u<\n", 4294967295);       
	// ft_printf(">%lu<\n", 4294967295);       
	// ft_printf(">%lu<\n", 4294967296);           
	// ft_printf(">%lu<\n", -42);                   
	// ft_printf(">%llu<\n", 4999999999); 

	return (0);
}
