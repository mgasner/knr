#include <stdio.h>

#define TRUE 1
#define FALSE 0

main()
{
	int c, last;

	last = FALSE;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			last = TRUE;
		else {
			if (last) {
				putchar(' ');
				last = FALSE;
			}
			putchar(c);
		}
	}
}
