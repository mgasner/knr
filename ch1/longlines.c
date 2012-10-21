#include <stdio.h>
#define MAXLINE 1000 /* maximum line length */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */

	max = 0;
	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len > 80) {
			printf("%s", line);
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
