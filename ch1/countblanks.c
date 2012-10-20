#include <stdio.h>

main()
{
	int c;
	double nb, nt, nl;

	nb = 0;
	nt = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++nb;
			continue;
		}
		if (c == '\t') {
			++nt;
			continue;
		}
		if (c == '\n')
			++nl;
	}
	printf("Blanks:\t\t%.0f\n", nb);
	printf("Tabs:\t\t%.0f\n", nt);
	printf("Newlines:\t%.0f\n", nl);
}
