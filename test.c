#include <stdio.h>

int	main()
{
	int		a, b;
	char	c;
	char	*str = "string";

	a = 3;
	b = -3;
	c = 'M';

/*	printf("STANDART TYPE d (i):\nnumber > 0\n");
	printf("This is test  0: |%3d|---|%5s|\n", a, "%3d");
	printf("This is test  1: |%+3d|---|%5s|\n", a, "%+3d");
	printf("This is test  2: |%-3d|---|%5s|\n", a, "%-3d");
	printf("This is test  3: |% 3d|---|%5s|\n", a, "% 3d");
	printf("This is test  4: |%03d|---|%5s|\n", a, "%03d");
	printf("This is test  5: |% +3d|---|%5s|\n", a, "% +3d");
	printf("This is test  6: |% -3d|---|%5s|\n", a, "% -3d");
	printf("This is test  7: |%+-3d|---|%5s|\n", a, "%+-3d");
	printf("This is test  8: |%0-3d|---|%5s|\n", a, "%0-3d");
	printf("This is test  9: |%0+3d|---|%5s|\n", a, "%0+3d");
	printf("This is test 10: |% 03d|---|%5s|\n", a, "% 03d");
	printf("This is test 11: |% -3d|---|%5s|\n\n", a, "% -3d");

	printf("number < 0\n");
	printf("This is test  0: |%3d|---|%5s|\n", b, "%3d");
	printf("This is test  1: |%+3d|---|%5s|\n", b, "%+3d");
	printf("This is test  2: |%-3d|---|%5s|\n", b, "%-3d");
	printf("This is test  3: |% 3d|---|%5s|\n", b, "% 3d");
	printf("This is test  4: |%03d|---|%5s|\n", b, "%03d");
	printf("This is test  5: |% +3d|---|%5s|\n", b, "% +3d");
	printf("This is test  6: |% -3d|---|%5s|\n", b, "% -3d");
	printf("This is test  7: |%+-3d|---|%5s|\n", b, "%+-3d");
	printf("This is test  8: |%0-3d|---|%5s|\n", b, "%0-3d");
	printf("This is test  9: |%0+3d|---|%5s|\n", b, "%0+3d");
	printf("This is test 10: |% 03d|---|%5s|\n", b, "% 03d");
	printf("This is test 11: |% -3d|---|%5s|\n\n", b, "% -3d");

	printf("STANDART TYPE u:\nnumber > 0\n");
	printf("This is test  0: |%3u|---|%5s|\n", a, "%3u");
	printf("This is test  1: |%+3u|---|%5s|\n", a, "%+3u");
	printf("This is test  2: |%-3u|---|%5s|\n", a, "%-3u");
	printf("This is test  3: |% 3u|---|%5s|\n", a, "% 3u");
	printf("This is test  4: |%03u|---|%5s|\n", a, "%03u");
	printf("This is test  5: |% +3u|---|%5s|\n", a, "% +3u");
	printf("This is test  6: |% -3u|---|%5s|\n", a, "% -3u");
	printf("This is test  7: |%+-3u|---|%5s|\n", a, "%+-3u");
	printf("This is test  8: |%0-3u|---|%5s|\n", a, "%0-3u");
	printf("This is test  9: |%0+3u|---|%5s|\n", a, "%0+3u");
	printf("This is test 10: |% 03u|---|%5s|\n", a, "% 03u");
	printf("This is test 11: |% -3u|---|%5s|\n\n", a, "% -3u");

	printf("number < 0\n");
	printf("This is test  1: |%3u|---|%5s|\n", b, "%3u");
	printf("This is test  1: |%+3u|---|%5s|\n", b, "%+3u");
	printf("This is test  2: |%-3u|---|%5s|\n", b, "%-3u");
	printf("This is test  3: |% 3u|---|%5s|\n", b, "% 3u");
	printf("This is test  4: |%03u|---|%5s|\n", b, "%03u");
	printf("This is test  5: |% +3u|---|%5s|\n", b, "% +3u");
	printf("This is test  6: |% -3u|---|%5s|\n", b, "% -3u");
	printf("This is test  7: |%+-3u|---|%5s|\n", b, "%+-3u");
	printf("This is test  8: |%0-3u|---|%5s|\n", b, "%0-3u");
	printf("This is test  9: |%0+3u|---|%5s|\n", b, "%0+3u");
	printf("This is test 10: |% 03u|---|%5s|\n", b, "% 03u");
	printf("This is test 11: |% -3u|---|%5s|\n\n", b, "% -3u");

	printf("STANDART TYPE o:\nnumber > 0\n");
	printf("This is test  0: |%3o|---|%5s|\n", a, "%3o");
	printf("This is test  1: |%+3o|---|%5s|\n", a, "%+3o");
	printf("This is test  2: |%-3o|---|%5s|\n", a, "%-3o");
	printf("This is test  3: |% 3o|---|%5s|\n", a, "% o");
	printf("This is test  4: |%#3o|---|%5s|\n", a, "%#3o");
	printf("This is test  5: |%03o|---|%5s|\n", a, "%03o");
	printf("This is test  6: |%#+3o|---|%5s|\n", a, "%#+3o");
	printf("This is test  7: |%#-3o|---|%5s|\n", a, "%#-3o");
	printf("This is test  8: |%#03o|---|%5s|\n", a, "%#03o");
	printf("This is test  9: |% #3o|---|%5s|\n", a, "% #3o");
	printf("This is test 10: |%+-3o|---|%5s|\n", a, "%+-3o");
	printf("This is test 11: |%+03o|---|%5s|\n", a, "%+03o");
	printf("This is test 12: |% +3o|---|%5s|\n", a, "% +3o");
	printf("This is test 13: |%-03o|---|%5s|\n", a, "%-03o");
	printf("This is test 14: |% -3o|---|%5s|\n", a, "% -3o");
	printf("This is test 15: |% 03o|---|%5s|\n\n", a, "% 03o");

	printf("number < 0\n");
	printf("This is test  0: |%3o|---|%5s|\n", b, "%3o");
	printf("This is test  1: |%+3o|---|%5s|\n", b, "%+3o");
	printf("This is test  2: |%-3o|---|%5s|\n", b, "%-3o");
	printf("This is test  3: |% 3o|---|%5s|\n", b, "% o");
	printf("This is test  4: |%#3o|---|%5s|\n", b, "%#3o");
	printf("This is test  5: |%03o|---|%5s|\n", b, "%03o");
	printf("This is test  6: |%#+3o|---|%5s|\n", b, "%#+3o");
	printf("This is test  7: |%#-3o|---|%5s|\n", b, "%#-3o");
	printf("This is test  8: |%#03o|---|%5s|\n", b, "%#03o");
	printf("This is test  9: |% #3o|---|%5s|\n", b, "% #3o");
	printf("This is test 10: |%+-3o|---|%5s|\n", b, "%+-3o");
	printf("This is test 11: |%+03o|---|%5s|\n", b, "%+03o");
	printf("This is test 12: |% +3o|---|%5s|\n", b, "% +3o");
	printf("This is test 13: |%-03o|---|%5s|\n", b, "%-03o");
	printf("This is test 14: |% -3o|---|%5s|\n", b, "% -3o");
	printf("This is test 15: |% 03o|---|%5s|\n\n", b, "% 03o");

	printf("STANDART TYPE x (X):\nnumber > 0\n");
	printf("This is test  0: |%5x|---|%5s|\n", a, "%5x");
	printf("This is test  1: |%+5x|---|%5s|\n", a, "%+5x");
	printf("This is test  2: |%-5x|---|%5s|\n", a, "%-5x");
	printf("This is test  3: |% 5x|---|%5s|\n", a, "% 5x");
	printf("This is test  4: |%#5x|---|%5s|\n", a, "%#5x");
	printf("This is test  5: |%05x|---|%5s|\n", a, "%05x");
	printf("This is test  6: |%#+5x|---|%5s|\n", a, "%#+5x");
	printf("This is test  7: |%#-5x|---|%5s|\n", a, "%#-5x");
	printf("This is test  8: |%#05x|---|%5s|\n", a, "%#05x");
	printf("This is test  9: |% #5x|---|%5s|\n", a, "% #5x");
	printf("This is test 10: |%+-5x|---|%5s|\n", a, "%+-5x");
	printf("This is test 11: |%+05x|---|%5s|\n", a, "%+05x");
	printf("This is test 12: |% +5x|---|%5s|\n", a, "% +5x");
	printf("This is test 13: |%-05x|---|%5s|\n", a, "%-05x");
	printf("This is test 14: |% -5x|---|%5s|\n", a, "% -5x");
	printf("This is test 15: |% 05x|---|%5s|\n\n", a, "% 05x");

	printf("number < 0\n");
	printf("This is test  0: |%5x|---|%5s|\n", b, "%5x");
	printf("This is test  1: |%+5x|---|%5s|\n", b, "%+5x");
	printf("This is test  2: |%-5x|---|%5s|\n", b, "%-5x");
	printf("This is test  3: |% 5x|---|%5s|\n", b, "% 5x");
	printf("This is test  4: |%#5x|---|%5s|\n", b, "%#5x");
	printf("This is test  5: |%05x|---|%5s|\n", b, "%05x");
	printf("This is test  6: |%#+5x|---|%5s|\n", b, "%#+5x");
	printf("This is test  7: |%#-5x|---|%5s|\n", b, "%#-5x");
	printf("This is test  8: |%#05x|---|%5s|\n", b, "%#05x");
	printf("This is test  9: |% #5x|---|%5s|\n", b, "% #5x");
	printf("This is test 10: |%+-5x|---|%5s|\n", b, "%+-5x");
	printf("This is test 11: |%+05x|---|%5s|\n", b, "%+05x");
	printf("This is test 12: |% +5x|---|%5s|\n", b, "% +5x");
	printf("This is test 13: |%-05x|---|%5s|\n", b, "%-05x");
	printf("This is test 14: |% -5x|---|%5s|\n", b, "% -5x");
	printf("This is test 15: |% 05x|---|%5s|\n", b, "% 05x");

	printf("STANDART TYPE c:\n");
	printf("This is test  0: |%5c|---|%5s|\n", c, "%5c");
	printf("This is test  1: |%+5c|---|%5s|\n", c, "%+5c");
	printf("This is test  2: |%-5c|---|%5s|\n", c, "%-5c");
	printf("This is test  3: |% 5c|---|%5s|\n", c, "% 5c");
	printf("This is test  4: |%#5c|---|%5s|\n", c, "%#5c");
	printf("This is test  5: |%05c|---|%5s|\n", c, "%05c");
	printf("This is test  6: |%#+5c|---|%5s|\n", c, "%#+5c");
	printf("This is test  7: |%#-5c|---|%5s|\n", c, "%#-5c");
	printf("This is test  8: |%#05c|---|%5s|\n", c, "%#05c");
	printf("This is test  9: |% #5c|---|%5s|\n", c, "% #5c");
	printf("This is test 10: |%+-5c|---|%5s|\n", c, "%+-5c");
	printf("This is test 11: |%+05c|---|%5s|\n", c, "%+05c");
	printf("This is test 12: |% +5c|---|%5s|\n", c, "% +5c");
	printf("This is test 13: |%-05c|---|%5s|\n", c, "%-05c");
	printf("This is test 14: |% -5c|---|%5s|\n", c, "% -5c");
	printf("This is test 15: |% 05c|---|%5s|\n", c, "% 05c");
*/
	printf("STANDART TYPE s:\n");
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