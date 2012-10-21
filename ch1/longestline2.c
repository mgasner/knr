#include <stdio.h>
#define MAXLINE 1000 /* maximum line length */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
	int len; /* current line length */
	int c;
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */

	max = 0;
	while ((len = mygetline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
		if (len == MAXLINE - 1)
			if (longest[MAXLINE - 2] != '\n') {
				while ((c = getchar()) != EOF && c != '\n')
					++max;
				if (c == '\n')
					++max;
			}
	}

	if (max > 0) /* there was a line */ {
		printf("Longest line: %d chars\n", max);
		printf("%s\n", longest);
		if (max > MAXLINE)
			printf("(truncated)\n");
	}
	else
		printf("Empty input!\n");
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
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to' */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
