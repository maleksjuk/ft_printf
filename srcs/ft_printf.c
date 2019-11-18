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
	(*p)->precision = 0;
	(*p)->int_val = 0;
	(*p)->uint_val = 0;
	(*p)->type = 0;
	(*p)->size = 0;
	(*p)->spec_mask = "diouxXcs";
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
	int		a, b;
	char	c;
	char	*str = "string";

	a = 3;
	b = -3;
	c = 'M';

/*	ft_printf("NO_STANDART TYPE d (i):\nnumber > 0\n");
	ft_printf("This is test  0: |%3d|---|%5s|\n", a, "%3d");
	ft_printf("This is test  1: |%+3d|---|%5s|\n", a, "%+3d");
	ft_printf("This is test  2: |%-3d|---|%5s|\n", a, "%-3d");
	ft_printf("This is test  3: |% 3d|---|%5s|\n", a, "% 3d");
	ft_printf("This is test  4: |%03d|---|%5s|\n", a, "%03d");
	ft_printf("This is test  5: |% +3d|---|%5s|\n", a, "% +3d");
	ft_printf("This is test  6: |% -3d|---|%5s|\n", a, "% -3d");
	ft_printf("This is test  7: |%+-3d|---|%5s|\n", a, "%+-3d");
	ft_printf("This is test  8: |%0-3d|---|%5s|\n", a, "%0-3d");
	ft_printf("This is test  9: |%0+3d|---|%5s|\n", a, "%0+3d");
	ft_printf("This is test 10: |% 03d|---|%5s|\n", a, "% 03d");
	ft_printf("This is test 11: |% -3d|---|%5s|\n\n", a, "% -3d");

	ft_printf("number < 0\n");
	ft_printf("This is test  0: |%3d|---|%5s|\n", b, "%3d");
	ft_printf("This is test  1: |%+3d|---|%5s|\n", b, "%+3d");
	ft_printf("This is test  2: |%-3d|---|%5s|\n", b, "%-3d");
	ft_printf("This is test  3: |% 3d|---|%5s|\n", b, "% 3d");
	ft_printf("This is test  4: |%03d|---|%5s|\n", b, "%03d");
	ft_printf("This is test  5: |% +3d|---|%5s|\n", b, "% +3d");
	ft_printf("This is test  6: |% -3d|---|%5s|\n", b, "% -3d");
	ft_printf("This is test  7: |%+-3d|---|%5s|\n", b, "%+-3d");
	ft_printf("This is test  8: |%0-3d|---|%5s|\n", b, "%0-3d");
	ft_printf("This is test  9: |%0+3d|---|%5s|\n", b, "%0+3d");
	ft_printf("This is test 10: |% 03d|---|%5s|\n", b, "% 03d");
	ft_printf("This is test 11: |% -3d|---|%5s|\n\n", b, "% -3d");

	ft_printf("NO_STANDART TYPE u:\nnumber > 0\n");
	ft_printf("This is test  0: |%3u|---|%5s|\n", a, "%3u");
	ft_printf("This is test  1: |%+3u|---|%5s|\n", a, "%+3u");
	ft_printf("This is test  2: |%-3u|---|%5s|\n", a, "%-3u");
	ft_printf("This is test  3: |% 3u|---|%5s|\n", a, "% 3u");
	ft_printf("This is test  4: |%03u|---|%5s|\n", a, "%03u");
	ft_printf("This is test  5: |% +3u|---|%5s|\n", a, "% +3u");
	ft_printf("This is test  6: |% -3u|---|%5s|\n", a, "% -3u");
	ft_printf("This is test  7: |%+-3u|---|%5s|\n", a, "%+-3u");
	ft_printf("This is test  8: |%0-3u|---|%5s|\n", a, "%0-3u");
	ft_printf("This is test  9: |%0+3u|---|%5s|\n", a, "%0+3u");
	ft_printf("This is test 10: |% 03u|---|%5s|\n", a, "% 03u");
	ft_printf("This is test 11: |% -3u|---|%5s|\n\n", a, "% -3u");

	ft_printf("number < 0\n");
	ft_printf("This is test  1: |%3u|---|%5s|\n", b, "%3u");
	ft_printf("This is test  1: |%+3u|---|%5s|\n", b, "%+3u");
	ft_printf("This is test  2: |%-3u|---|%5s|\n", b, "%-3u");
	ft_printf("This is test  3: |% 3u|---|%5s|\n", b, "% 3u");
	ft_printf("This is test  4: |%03u|---|%5s|\n", b, "%03u");
	ft_printf("This is test  5: |% +3u|---|%5s|\n", b, "% +3u");
	ft_printf("This is test  6: |% -3u|---|%5s|\n", b, "% -3u");
	ft_printf("This is test  7: |%+-3u|---|%5s|\n", b, "%+-3u");
	ft_printf("This is test  8: |%0-3u|---|%5s|\n", b, "%0-3u");
	ft_printf("This is test  9: |%0+3u|---|%5s|\n", b, "%0+3u");
	ft_printf("This is test 10: |% 03u|---|%5s|\n", b, "% 03u");
	ft_printf("This is test 11: |% -3u|---|%5s|\n\n", b, "% -3u");

	ft_printf("NO_STANDART TYPE o:\nnumber > 0\n");
	ft_printf("This is test  0: |%3o|---|%5s|\n", a, "%3o");
	ft_printf("This is test  1: |%+3o|---|%5s|\n", a, "%+3o");
	ft_printf("This is test  2: |%-3o|---|%5s|\n", a, "%-3o");
	ft_printf("This is test  3: |% 3o|---|%5s|\n", a, "% o");
	ft_printf("This is test  4: |%#3o|---|%5s|\n", a, "%#3o");
	ft_printf("This is test  5: |%03o|---|%5s|\n", a, "%03o");
	ft_printf("This is test  6: |%#+3o|---|%5s|\n", a, "%#+3o");
	ft_printf("This is test  7: |%#-3o|---|%5s|\n", a, "%#-3o");
	ft_printf("This is test  8: |%#03o|---|%5s|\n", a, "%#03o");
	ft_printf("This is test  9: |% #3o|---|%5s|\n", a, "% #3o");
	ft_printf("This is test 10: |%+-3o|---|%5s|\n", a, "%+-3o");
	ft_printf("This is test 11: |%+03o|---|%5s|\n", a, "%+03o");
	ft_printf("This is test 12: |% +3o|---|%5s|\n", a, "% +3o");
	ft_printf("This is test 13: |%-03o|---|%5s|\n", a, "%-03o");
	ft_printf("This is test 14: |% -3o|---|%5s|\n", a, "% -3o");
	ft_printf("This is test 15: |% 03o|---|%5s|\n\n", a, "% 03o");

	ft_printf("number < 0\n");
	ft_printf("This is test  0: |%3o|---|%5s|\n", b, "%3o");
	ft_printf("This is test  1: |%+3o|---|%5s|\n", b, "%+3o");
	ft_printf("This is test  2: |%-3o|---|%5s|\n", b, "%-3o");
	ft_printf("This is test  3: |% 3o|---|%5s|\n", b, "% o");
	ft_printf("This is test  4: |%#3o|---|%5s|\n", b, "%#3o");
	ft_printf("This is test  5: |%03o|---|%5s|\n", b, "%03o");
	ft_printf("This is test  6: |%#+3o|---|%5s|\n", b, "%#+3o");
	ft_printf("This is test  7: |%#-3o|---|%5s|\n", b, "%#-3o");
	ft_printf("This is test  8: |%#03o|---|%5s|\n", b, "%#03o");
	ft_printf("This is test  9: |% #3o|---|%5s|\n", b, "% #3o");
	ft_printf("This is test 10: |%+-3o|---|%5s|\n", b, "%+-3o");
	ft_printf("This is test 11: |%+03o|---|%5s|\n", b, "%+03o");
	ft_printf("This is test 12: |% +3o|---|%5s|\n", b, "% +3o");
	ft_printf("This is test 13: |%-03o|---|%5s|\n", b, "%-03o");
	ft_printf("This is test 14: |% -3o|---|%5s|\n", b, "% -3o");
	ft_printf("This is test 15: |% 03o|---|%5s|\n\n", b, "% 03o");

	ft_printf("NO_STANDART TYPE x (X):\nnumber > 0\n");
	ft_printf("This is test  0: |%5x|---|%5s|\n", a, "%5x");
	ft_printf("This is test  1: |%+5x|---|%5s|\n", a, "%+5x");
	ft_printf("This is test  2: |%-5x|---|%5s|\n", a, "%-5x");
	ft_printf("This is test  3: |% 5x|---|%5s|\n", a, "% 5x");
	ft_printf("This is test  4: |%#5x|---|%5s|\n", a, "%#5x");
	ft_printf("This is test  5: |%05x|---|%5s|\n", a, "%05x");
	ft_printf("This is test  6: |%#+5x|---|%5s|\n", a, "%#+5x");
	ft_printf("This is test  7: |%#-5x|---|%5s|\n", a, "%#-5x");
	ft_printf("This is test  8: |%#05x|---|%5s|\n", a, "%#05x");
	ft_printf("This is test  9: |% #5x|---|%5s|\n", a, "% #5x");
	ft_printf("This is test 10: |%+-5x|---|%5s|\n", a, "%+-5x");
	ft_printf("This is test 11: |%+05x|---|%5s|\n", a, "%+05x");
	ft_printf("This is test 12: |% +5x|---|%5s|\n", a, "% +5x");
	ft_printf("This is test 13: |%-05x|---|%5s|\n", a, "%-05x");
	ft_printf("This is test 14: |% -5x|---|%5s|\n", a, "% -5x");
	ft_printf("This is test 15: |% 05x|---|%5s|\n\n", a, "% 05x");

	ft_printf("number < 0\n");
	ft_printf("This is test  0: |%5x|---|%5s|\n", b, "%5x");
	ft_printf("This is test  1: |%+5x|---|%5s|\n", b, "%+5x");
	ft_printf("This is test  2: |%-5x|---|%5s|\n", b, "%-5x");
	ft_printf("This is test  3: |% 5x|---|%5s|\n", b, "% 5x");
	ft_printf("This is test  4: |%#5x|---|%5s|\n", b, "%#5x");
	ft_printf("This is test  5: |%05x|---|%5s|\n", b, "%05x");
	ft_printf("This is test  6: |%#+5x|---|%5s|\n", b, "%#+5x");
	ft_printf("This is test  7: |%#-5x|---|%5s|\n", b, "%#-5x");
	ft_printf("This is test  8: |%#05x|---|%5s|\n", b, "%#05x");
	ft_printf("This is test  9: |% #5x|---|%5s|\n", b, "% #5x");
	ft_printf("This is test 10: |%+-5x|---|%5s|\n", b, "%+-5x");
	ft_printf("This is test 11: |%+05x|---|%5s|\n", b, "%+05x");
	ft_printf("This is test 12: |% +5x|---|%5s|\n", b, "% +5x");
	ft_printf("This is test 13: |%-05x|---|%5s|\n", b, "%-05x");
	ft_printf("This is test 14: |% -5x|---|%5s|\n", b, "% -5x");
	ft_printf("This is test 15: |% 05x|---|%5s|\n", b, "% 05x");

	ft_printf("NO_STANDART TYPE c:\n");
	ft_printf("This is test  0: |%5c|---|%5s|\n", c, "%5c");
	ft_printf("This is test  1: |%+5c|---|%5s|\n", c, "%+5c");
	ft_printf("This is test  2: |%-5c|---|%5s|\n", c, "%-5c");
	ft_printf("This is test  3: |% 5c|---|%5s|\n", c, "% 5c");
	ft_printf("This is test  4: |%#5c|---|%5s|\n", c, "%#5c");
	ft_printf("This is test  5: |%05c|---|%5s|\n", c, "%05c");
	ft_printf("This is test  6: |%#+5c|---|%5s|\n", c, "%#+5c");
	ft_printf("This is test  7: |%#-5c|---|%5s|\n", c, "%#-5c");
	ft_printf("This is test  8: |%#05c|---|%5s|\n", c, "%#05c");
	ft_printf("This is test  9: |% #5c|---|%5s|\n", c, "% #5c");
	ft_printf("This is test 10: |%+-5c|---|%5s|\n", c, "%+-5c");
	ft_printf("This is test 11: |%+05c|---|%5s|\n", c, "%+05c");
	ft_printf("This is test 12: |% +5c|---|%5s|\n", c, "% +5c");
	ft_printf("This is test 13: |%-05c|---|%5s|\n", c, "%-05c");
	ft_printf("This is test 14: |% -5c|---|%5s|\n", c, "% -5c");
	ft_printf("This is test 15: |% 05c|---|%5s|\n", c, "% 05c");
*/
	printf("NO_STANDART TYPE s:\n");
	printf("This is test  0: |%5s|---|%5s|\n", str, "%5s");
	printf("This is test  1: |%+5s|---|%5s|\n", str, "%+5s");
	printf("This is test  2: |%-5s|---|%5s|\n", str, "%-5s");
	printf("This is test  3: |% 5s|---|%5s|\n", str, "% 5s");
	printf("This is test  4: |%#5s|---|%5s|\n", str, "%#5s");
	printf("This is test  5: |%05s|---|%5s|\n", str, "%05s");
	printf("This is test  6: |%#+5s|---|%5s|\n", str, "%#+5s");
	printf("This is test  7: |%#-5s|---|%5s|\n", str, "%#-5s");
	printf("This is test  8: |%#05s|---|%5s|\n", str, "%#05s");
	printf("This is test  9: |% #5s|---|%5s|\n", str, "% #5s");
	printf("This is test 10: |%+-5s|---|%5s|\n", str, "%+-5s");
	printf("This is test 11: |%+05s|---|%5s|\n", str, "%+05s");
	printf("This is test 12: |% +5s|---|%5s|\n", str, "% +5s");
	printf("This is test 13: |%-05s|---|%5s|\n", str, "%-05s");
	printf("This is test 14: |% -5s|---|%5s|\n", str, "% -5s");
	printf("This is test 15: |% 05s|---|%5s|\n", str, "% 05s");

	return (0);
}
