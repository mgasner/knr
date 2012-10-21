#include <stdio.h>
#define MAXLINE 1000 /* maximum line length */

int mygetline(char line[], int maxline);

/* remove trailing blanks and tabs, delete blank lines */
main()
{
	int i, last;
	int len; /* length of current line */
	char line[MAXLINE]; /* current input line */

	while ((len = mygetline(line, MAXLINE)) > 0) {
		last = 0;
		for (i = 0; i < len - 1; i++)
			if (line[i] != '\t' && line[i] != ' ' && line[i] != '\n')
				last = i;
		if (last > 0) {
			for (i = 0; i <= last; i++)
				putchar(line[i]);
			putchar('\n');
		}
	}
	return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	else if (c != EOF)
		while ((c = getchar()) != EOF && c != '\n')
			;
	s[i] = '\0';
	return i;
}
