#include <stdio.h>

int	main()
{
	int	a, b;

	a = 3;
	b = -3;

	printf("STANDART TYPE d (i): number > 0\n");
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

	printf("STANDART TYPE d (i): number < 0\n");
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

	printf("STANDART TYPE u: number > 0\n");
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

	printf("STANDART TYPE u: number < 0\n");
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

	printf("STANDART TYPE o: number > 0\n");
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

	printf("STANDART TYPE o: number < 0\n");
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

	printf("STANDART TYPE x (X): number > 0\n");
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

	printf("STANDART TYPE x (X): number < 0\n");
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
	return (0);
}