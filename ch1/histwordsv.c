#include <stdio.h>
#include <math.h>

#define IN 1
#define OUT 0

main()
{
	int i, j, n, c, state, hmax;
	int hist[10], max[10];
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
	step = hmax / 20.0;

	for (i = 0; i < 10; i++) {
		if (hist[i] == 0)
			max[i] = 0;
		else
			max[i] = floor(hist[i] / step);
	}

	for (i = 20; i > 0; i--) {
		for (j = 0; j < 10; j++) {
			if (max[j] >= i)
				printf("   .");
			else
				printf("    ");
		}
		printf("\n");
	}
	
	for (i = 0; i < 40; i++)
		printf("-");
	printf("\n");

	for (j = 0; j < 10; j++) {
		if (j == 9)
			printf(" +10");
		else
			printf("%4d", j + 1);
	}
	printf("\n");
}
