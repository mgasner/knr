#include <stdio.h>
#define MAXLINE 1000 /* maximum line length */

int mygetline(char line[], int maxline);
void reverse(char s[]);

/* reverse input one line at a time */
main()
{
	char line[MAXLINE]; /* current input line */

	while (mygetline(line, MAXLINE) > 0) {
		reverse(line);
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

void reverse(char s[])
{
	int i, j, c, len;
	len = 0;
	while (s[len] != '\0')
		len++;

	i = 0;
	j = len - 1;
	while (i < len / 2) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}