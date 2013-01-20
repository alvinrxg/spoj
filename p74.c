#include <stdio.h>
#include <math.h>

int main()
{
	long cases;
	long test;
	long i;
	long j, sq_var;
	long long sum;

	scanf("%ld", &cases);
	i = 0;
	while (i++ < cases) {
		scanf("%ld", &test);

		/* WTF this solution? */
		if (test == 1) {
			printf("0\n");
			continue;
		}

		sq_var = sqrt (test);
		sum = 1;
		for (j = 2; j <= sq_var; j++) {
			if (test % j == 0) {
				sum += j;
				if (!(j * j == test)) {
					sum += test / j;
				}
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
