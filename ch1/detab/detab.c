#include <stdio.h>

#define TABSTOP 4

//	test	a	ab	abc	abcd	abcde	
main()
{
	int c, i, j;
	
	i = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (j = TABSTOP - (i % TABSTOP); j > 0; j--)
				putchar(' ');
			i = 0;
		}
		else if (c == '\n') {
			putchar(c);
			i = 0;
		}
		else {
			putchar(c);
			++i;
		}
	}
}
