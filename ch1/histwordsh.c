#include <stdio.h>
#include <math.h>

#define IN 1
#define OUT 0

main()
{
	int i, j, n, c, state, hmax, max;
	int hist[10];
	float step;

	n = 0;
	state = OUT;
	for (i = 0; i < 10; i++) {
		hist[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				if (n > 10)
					++hist[9];
				else
					++hist[n - 1];
			}
			n = 0;
			state = OUT;
		}
		else {
			state = IN;
			++n;
		}
	}

	hmax = 1;
	for (i = 0; i< 10; i++) {
		if (hist[i] > hmax)
			hmax = hist[i];
	}
	step = hmax / 76.0;

	for (i = 0; i < 10; i++) {
		if (i == 9)
			printf("+10 ");
		else
			printf("%3d ", i + 1);
		if (hist[i] == 0)
			max = 0;
		else
			max = floor(hist[i] / step);
		for (j = 0; j < max; j++) {
			printf(".");
		}
		printf("\n");
	}
}
