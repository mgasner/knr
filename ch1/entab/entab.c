#include <stdio.h>

#define TABSTOP 4

//	a	ab	abc	abcd	f
//	a 	b  	c   	d  	f
main()
{
	int i, c, n, s;
	s = n = i = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			if (s == 0 && i > 0)
				s = i;
			if (c == ' ') {
				++i;
				++n;
			} else if (c == '\t') {
				i++;
				i += TABSTOP - (i % TABSTOP);
				n += TABSTOP - (n % TABSTOP);
			}
		}
		else {
			if (n > 0) {
				while (((s + n) / TABSTOP) > 0 && n > 1) {
					putchar('\t');
					n -= TABSTOP;
				}
				for (n; n > 0; n--)
					putchar(' ');
			}
			s = n = 0;
			if (c == '\n')
				i = 0;
			else
				i++;
			putchar(c);
		}
	}
}