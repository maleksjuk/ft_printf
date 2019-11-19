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
	(*p)->spec_mask = "diouxXcsf";
	(*p)->size_mask = "hl";
	return (0);
}

int		ft_printf(const char* format, ...)
{
	t_printf *p;

	if (!(p = (t_printf*)malloc(sizeof(*p))))
		return (-1);
	va_start(p->ap, format);
	p->index = 0;
	p->final_str = NULL;
	p->format = (char *)format;
	while (format[p->index] != '\0')
	{
		ft_construct(&p);
		if (ft_pars(&p) == -1)
			break ;
	}
	ft_final(&p);
	va_end(p->ap);
//	ft_putchar('\n');
	return (p->final_len);
}

int		main(void)
{
//	ft_printf("%.10f\n", 9873.0009999);

	int		a, b, e;
	char	c;
	char	*str = "string";

	a = 12;
	b = -3;
	c = 'M';
	e = 2;

	ft_printf("NO_STANDART TYPE d (i):\nnumber > 0\n");
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

	return (0);
}
