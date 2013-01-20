/* http://www.spoj.pl/problems/HANGOVER/ */
#include <stdio.h>

int main()
{
	float c;
	long i;
	float sum;

	while (1) {
		scanf("%f", &c);
		if (c == 0.00)
			break;
		sum = 0.0;
		for (i = 2;; i++) {
			sum += (float)1 / i;
			if (sum > c)
				break;
		}
		printf("%ld card(s)\n", i - 1);
	}

	return 0;
}
