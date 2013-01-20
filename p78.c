/* http://www.spoj.pl/problems/MARBLES/ */
/*	need bigger memory	*/

#include <stdio.h>

int main()
{
	int t;
	long n, k;
	long long x;
	int jj;
	long i, j;
	long k_min, k_max;

	scanf("%d", &t);
	jj = 0;
	while (jj++ < t) {
		scanf("%ld %ld", &n, &k);

		if (n == k) {
			printf("1\n");
			continue;
		}

		n--;
		k--;

		k_max = (n - k) > k ? n - k : k;
		k_min = n - k_max;
		x = 1;
		j = 2;
		for (i = k_max + 1; i <= n; i++) {
			if (i % j == 0 && j <= k_min) {
				x *= i / j;
				j++;
			}
			else {
				x *= i;
			}
printf("i = %ld\tj = %ld\tk_max = %ld\tk_min = %ld\tn = %ld\tx = %lld\n", i, j, k_max, k_min, n, x);
		}
		for (; j <= k_min; j++) {
			x /= j;
printf("j = %ld\tx = %lld\n", j, x);
		}
		printf("%lld\n", x);
	}
	return 0;
}
