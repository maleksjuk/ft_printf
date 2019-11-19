#include <stdio.h>

int	main()
{
	int		a, b, e;
	char	c;
	char	*str = "string";

	a = 12;
	b = -3;
	c = 'M';
	e = 2;

	printf("STANDART TYPE d (i):\nnumber > 0\n");
	printf("This is test  0: |%3.*d|---|%5s|\n", e, a, "%3.*d");
	printf("This is test  1: |%+3.*d|---|%5s|\n", e, a, "%+3.*d");
	printf("This is test  2: |%-3.*d|---|%5s|\n", e, a, "%-3.*d");
	printf("This is test  3: |% 3.*d|---|%5s|\n", e, a, "% 3.*d");
	printf("This is test  4: |%03.*d|---|%5s|\n", e, a, "%03.*d");
	printf("This is test  5: |% +3.*d|---|%5s|\n", e, a, "% +3.*d");
	printf("This is test  6: |% -3.*d|---|%5s|\n", e, a, "% -3.*d");
	printf("This is test  7: |%+-3.*d|---|%5s|\n", e, a, "%+-3.*d");
	printf("This is test  8: |%0-3.*d|---|%5s|\n", e, a, "%0-3.*d");
	printf("This is test  9: |%0+3.*d|---|%5s|\n", e, a, "%0+3.*d");
	printf("This is test 10: |% 03.*d|---|%5s|\n", e, a, "% 03.*d");
	printf("This is test 11: |% -3.*d|---|%5s|\n\n", e, a, "% -3.*d");

	printf("number < 0\n");
	printf("This is test  0: |%3.*d|---|%5s|\n", e, b, "%3.*d");
	printf("This is test  1: |%+3.*d|---|%5s|\n", e, b, "%+3.*d");
	printf("This is test  2: |%-3.*d|---|%5s|\n", e, b, "%-3.*d");
	printf("This is test  3: |% 3.*d|---|%5s|\n", e, b, "% 3.*d");
	printf("This is test  4: |%03.*d|---|%5s|\n", e, b, "%03.*d");
	printf("This is test  5: |% +3.*d|---|%5s|\n", e, b, "% +3.*d");
	printf("This is test  6: |% -3.*d|---|%5s|\n", e, b, "% -3.*d");
	printf("This is test  7: |%+-3.*d|---|%5s|\n", e, b, "%+-3.*d");
	printf("This is test  8: |%0-3.*d|---|%5s|\n", e, b, "%0-3.*d");
	printf("This is test  9: |%0+3.*d|---|%5s|\n", e, b, "%0+3.*d");
	printf("This is test 10: |% 03.*d|---|%5s|\n", e, b, "% 03.*d");
	printf("This is test 11: |% -3.*d|---|%5s|\n\n", e, b, "% -3.*d");

	printf("STANDART TYPE u:\nnumber > 0\n");
	printf("This is test  0: |%3.*u|---|%5s|\n", e, a, "%3.*u");
	printf("This is test  1: |%+3.*u|---|%5s|\n", e, a, "%+3.*u");
	printf("This is test  2: |%-3.*u|---|%5s|\n", e, a, "%-3.*u");
	printf("This is test  3: |% 3.*u|---|%5s|\n", e, a, "% 3.*u");
	printf("This is test  4: |%03.*u|---|%5s|\n", e, a, "%03.*u");
	printf("This is test  5: |% +3.*u|---|%5s|\n", e, a, "% +3.*u");
	printf("This is test  6: |% -3.*u|---|%5s|\n", e, a, "% -3.*u");
	printf("This is test  7: |%+-3.*u|---|%5s|\n", e, a, "%+-3.*u");
	printf("This is test  8: |%0-3.*u|---|%5s|\n", e, a, "%0-3.*u");
	printf("This is test  9: |%0+3.*u|---|%5s|\n", e, a, "%0+3.*u");
	printf("This is test 10: |% 03.*u|---|%5s|\n", e, a, "% 03.*u");
	printf("This is test 11: |% -3.*u|---|%5s|\n\n", e, a, "% -3.*u");

	printf("number < 0\n");
	printf("This is test  1: |%3.*u|---|%5s|\n", e, b, "%3.*u");
	printf("This is test  1: |%+3.*u|---|%5s|\n", e, b, "%+3.*u");
	printf("This is test  2: |%-3.*u|---|%5s|\n", e, b, "%-3.*u");
	printf("This is test  3: |% 3.*u|---|%5s|\n", e, b, "% 3.*u");
	printf("This is test  4: |%03.*u|---|%5s|\n", e, b, "%03.*u");
	printf("This is test  5: |% +3.*u|---|%5s|\n", e, b, "% +3.*u");
	printf("This is test  6: |% -3.*u|---|%5s|\n", e, b, "% -3.*u");
	printf("This is test  7: |%+-3.*u|---|%5s|\n", e, b, "%+-3.*u");
	printf("This is test  8: |%0-3.*u|---|%5s|\n", e, b, "%0-3.*u");
	printf("This is test  9: |%0+3.*u|---|%5s|\n", e, b, "%0+3.*u");
	printf("This is test 10: |% 03.*u|---|%5s|\n", e, b, "% 03.*u");
	printf("This is test 11: |% -3.*u|---|%5s|\n\n", e, b, "% -3.*u");

	printf("STANDART TYPE o:\nnumber > 0\n");
	printf("This is test  0: |%3.*o|---|%5s|\n", e, a, "%3.*o");
	printf("This is test  1: |%+3.*o|---|%5s|\n", e, a, "%+3.*o");
	printf("This is test  2: |%-3.*o|---|%5s|\n", e, a, "%-3.*o");
	printf("This is test  3: |% 3.*o|---|%5s|\n", e, a, "% 3.*o");
	printf("This is test  4: |%#3.*o|---|%5s|\n", e, a, "%#3.*o");
	printf("This is test  5: |%03.*o|---|%5s|\n", e, a, "%03.*o");
	printf("This is test  6: |%#+3.*o|---|%5s|\n", e, a, "%#+3.*o");
	printf("This is test  7: |%#-3.*o|---|%5s|\n", e, a, "%#-3.*o");
	printf("This is test  8: |%#03.*o|---|%5s|\n", e, a, "%#03.*o");
	printf("This is test  9: |% #3.*o|---|%5s|\n", e, a, "% #3.*o");
	printf("This is test 10: |%+-3.*o|---|%5s|\n", e, a, "%+-3.*o");
	printf("This is test 11: |%+03.*o|---|%5s|\n", e, a, "%+03.*o");
	printf("This is test 12: |% +3.*o|---|%5s|\n", e, a, "% +3.*o");
	printf("This is test 13: |%-03.*o|---|%5s|\n", e, a, "%-03.*o");
	printf("This is test 14: |% -3.*o|---|%5s|\n", e, a, "% -3.*o");
	printf("This is test 15: |% 03.*o|---|%5s|\n\n", e, a, "% 03.*o");

	printf("number < 0\n");
	printf("This is test  0: |%3.*o|---|%5s|\n", e, b, "%3.*o");
	printf("This is test  1: |%+3.*o|---|%5s|\n", e, b, "%+3.*o");
	printf("This is test  2: |%-3.*o|---|%5s|\n", e, b, "%-3.*o");
	printf("This is test  3: |% 3.*o|---|%5s|\n", e, b, "% 3.*o");
	printf("This is test  4: |%#3.*o|---|%5s|\n", e, b, "%#3.*o");
	printf("This is test  5: |%03.*o|---|%5s|\n", e, b, "%03.*o");
	printf("This is test  6: |%#+3.*o|---|%5s|\n", e, b, "%#+3.*o");
	printf("This is test  7: |%#-3.*o|---|%5s|\n", e, b, "%#-3.*o");
	printf("This is test  8: |%#03.*o|---|%5s|\n", e, b, "%#03.*o");
	printf("This is test  9: |% #3.*o|---|%5s|\n", e, b, "% #3.*o");
	printf("This is test 10: |%+-3.*o|---|%5s|\n", e, b, "%+-3.*o");
	printf("This is test 11: |%+03.*o|---|%5s|\n", e, b, "%+03.*o");
	printf("This is test 12: |% +3.*o|---|%5s|\n", e, b, "% +3.*o");
	printf("This is test 13: |%-03.*o|---|%5s|\n", e, b, "%-03.*o");
	printf("This is test 14: |% -3.*o|---|%5s|\n", e, b, "% -3.*o");
	printf("This is test 15: |% 03.*o|---|%5s|\n\n", e, b, "% 03.*o");

	printf("STANDART TYPE x (X):\nnumber > 0\n");
	printf("This is test  0: |%5.*x|---|%5s|\n", e, a, "%5.*x");
	printf("This is test  1: |%+5.*x|---|%5s|\n", e, a, "%+5.*x");
	printf("This is test  2: |%-5.*x|---|%5s|\n", e, a, "%-5.*x");
	printf("This is test  3: |% 5.*x|---|%5s|\n", e, a, "% 5.*x");
	printf("This is test  4: |%#5.*x|---|%5s|\n", e, a, "%#5.*x");
	printf("This is test  5: |%05.*x|---|%5s|\n", e, a, "%05.*x");
	printf("This is test  6: |%#+5.*x|---|%5s|\n", e, a, "%#+5.*x");
	printf("This is test  7: |%#-5.*x|---|%5s|\n", e, a, "%#-5.*x");
	printf("This is test  8: |%#05.*x|---|%5s|\n", e, a, "%#05.*x");
	printf("This is test  9: |% #5.*x|---|%5s|\n", e, a, "% #5.*x");
	printf("This is test 10: |%+-5.*x|---|%5s|\n", e, a, "%+-5.*x");
	printf("This is test 11: |%+05.*x|---|%5s|\n", e, a, "%+05.*x");
	printf("This is test 12: |% +5.*x|---|%5s|\n", e, a, "% +5.*x");
	printf("This is test 13: |%-05.*x|---|%5s|\n", e, a, "%-05.*x");
	printf("This is test 14: |% -5.*x|---|%5s|\n", e, a, "% -5.*x");
	printf("This is test 15: |% 05.*x|---|%5s|\n\n", e, a, "% 05.*x");

	printf("number < 0\n");
	printf("This is test  0: |%5.*x|---|%5s|\n", e, b, "%5.*x");
	printf("This is test  1: |%+5.*x|---|%5s|\n", e, b, "%+5.*x");
	printf("This is test  2: |%-5.*x|---|%5s|\n", e, b, "%-5.*x");
	printf("This is test  3: |% 5.*x|---|%5s|\n", e, b, "% 5.*x");
	printf("This is test  4: |%#5.*x|---|%5s|\n", e, b, "%#5.*x");
	printf("This is test  5: |%05.*x|---|%5s|\n", e, b, "%05.*x");
	printf("This is test  6: |%#+5.*x|---|%5s|\n", e, b, "%#+5.*x");
	printf("This is test  7: |%#-5.*x|---|%5s|\n", e, b, "%#-5.*x");
	printf("This is test  8: |%#05.*x|---|%5s|\n", e, b, "%#05.*x");
	printf("This is test  9: |% #5.*x|---|%5s|\n", e, b, "% #5.*x");
	printf("This is test 10: |%+-5.*x|---|%5s|\n", e, b, "%+-5.*x");
	printf("This is test 11: |%+05.*x|---|%5s|\n", e, b, "%+05.*x");
	printf("This is test 12: |% +5.*x|---|%5s|\n", e, b, "% +5.*x");
	printf("This is test 13: |%-05.*x|---|%5s|\n", e, b, "%-05.*x");
	printf("This is test 14: |% -5.*x|---|%5s|\n", e, b, "% -5.*x");
	printf("This is test 15: |% 05.*x|---|%5s|\n\n", e, b, "% 05.*x");

	printf("STANDART TYPE c:\n");
	printf("This is test  0: |%5.*c|---|%5s|\n", e, c, "%5.*c");
	printf("This is test  1: |%+5.*c|---|%5s|\n", e, c, "%+5.*c");
	printf("This is test  2: |%-5.*c|---|%5s|\n", e, c, "%-5.*c");
	printf("This is test  3: |% 5.*c|---|%5s|\n", e, c, "% 5.*c");
	printf("This is test  4: |%#5.*c|---|%5s|\n", e, c, "%#5.*c");
	printf("This is test  5: |%05.*c|---|%5s|\n", e, c, "%05.*c");
	printf("This is test  6: |%#+5.*c|---|%5s|\n", e, c, "%#+5.*c");
	printf("This is test  7: |%#-5.*c|---|%5s|\n", e, c, "%#-5.*c");
	printf("This is test  8: |%#05.*c|---|%5s|\n", e, c, "%#05.*c");
	printf("This is test  9: |% #5.*c|---|%5s|\n", e, c, "% #5.*c");
	printf("This is test 10: |%+-5.*c|---|%5s|\n", e, c, "%+-5.*c");
	printf("This is test 11: |%+05.*c|---|%5s|\n", e, c, "%+05.*c");
	printf("This is test 12: |% +5.*c|---|%5s|\n", e, c, "% +5.*c");
	printf("This is test 13: |%-05.*c|---|%5s|\n", e, c, "%-05.*c");
	printf("This is test 14: |% -5.*c|---|%5s|\n", e, c, "% -5.*c");
	printf("This is test 15: |% 05.*c|---|%5s|\n\n", e, c, "% 05.*c");

	printf("STANDART TYPE s:\n");
	printf("This is test  0: |%5.*s|---|%5s|\n", e, str, "%5.*s");
	printf("This is test  1: |%+5.*s|---|%5s|\n", e, str, "%+5.*s");
	printf("This is test  2: |%-5.*s|---|%5s|\n", e, str, "%-5.*s");
	printf("This is test  3: |% 5.*s|---|%5s|\n", e, str, "% 5.*s");
	printf("This is test  4: |%#5.*s|---|%5s|\n", e, str, "%#5.*s");
	printf("This is test  5: |%05.*s|---|%5s|\n", e, str, "%05.*s");
	printf("This is test  6: |%#+5.*s|---|%5s|\n", e, str, "%#+5.*s");
	printf("This is test  7: |%#-5.*s|---|%5s|\n", e, str, "%#-5.*s");
	printf("This is test  8: |%#05.*s|---|%5s|\n", e, str, "%#05.*s");
	printf("This is test  9: |% #5.*s|---|%5s|\n", e, str, "% #5.*s");
	printf("This is test 10: |%+-5.*s|---|%5s|\n", e, str, "%+-5.*s");
	printf("This is test 11: |%+05.*s|---|%5s|\n", e, str, "%+05.*s");
	printf("This is test 12: |% +5.*s|---|%5s|\n", e, str, "% +5.*s");
	printf("This is test 13: |%-05.*s|---|%5s|\n", e, str, "%-05.*s");
	printf("This is test 14: |% -5.*s|---|%5s|\n", e, str, "% -5.*s");
	printf("This is test 15: |% 05.*s|---|%5s|\n", e, str, "% 05.*s");

	return (0);
}