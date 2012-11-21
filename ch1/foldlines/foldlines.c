#include <stdio.h>

#define LINELENGTH 80
#define MAXBUFFERSIZE 8000

main()
{
	int c, i, j, n, b;
	char buffer[MAXBUFFERSIZE];

	n = b = 0;

	while ((c = getchar()) != EOF) {
		buffer[b] = c; // buffer the character
		b++;
		if (n + b < LINELENGTH) { // if we still fit on the line
			if (c == '\n') {
				for (i = 0; i < b; i++)
					putchar(buffer[i]);
				n = b = 0;
			} else if (c == ' ' || c == '\t') {
				for (i = 0; i < b; i++)
					putchar(buffer[i]);
				n += b;
				b = 0;
			}
		} else {
			// if the word fits on a single line
			if (b < LINELENGTH) {
				if (c == '\n' || c == ' ' || c == '\t') {
					putchar('\n');
					for (i = 0; i < b; i++)
						putchar(buffer[i]);
					if (c == '\n')
						n = 0;
					else
						n = b;
					b = 0;
				}
			} else {
				if (c == '\n' || c == ' ' || c == '\t') {
					j = n;
					for (i = 0; i < b; i++) {
						if (j > LINELENGTH - 3) {
							putchar('\n');
							j = 0;
						}
						if (j == LINELENGTH - 3) {
							putchar('\\');
							putchar('\n');
							j = 0;
						}
						putchar(buffer[i]);
						j++;
					}
					if (c == '\n')
						n = 0;
					else
						n = b % LINELENGTH;
					b = 0;
				}
			}
		}
	}
}
