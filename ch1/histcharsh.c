#include <stdio.h>
#include <math.h>

main()
{
	int i, j, c, hmax, max;
	int hist[256];
	float step;

	for (i = 0; i < 256; i++) {
		hist[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		++hist[c];
	}

	hmax = 1;
	for (i = 0; i < 256; i++) {
		if (hist[i] > hmax)
			hmax = hist[i];
	}
	step = hmax / 76.0;

	for (i = 0; i < 256; i++) {
		if (hist[i] == 0)
			continue;
		else {
			if (i == '\n')
				printf(" \\n ");
			else if (i == ' ')
				printf(" \\s ");
			else if (i == '\t')
				printf(" \\t ");
			else {
				printf("  ");
				putchar(i);
				printf(" ");
			}
			max = floor(hist[i] / step);
			for (j = 0; j < max; j++) {
				printf(".");
			}
			printf("\n");
		}
	}
}
