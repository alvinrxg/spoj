/* http://www.spoj.pl/problems/AMR10F/ */

#include <stdio.h>

int main()
{
	int t;
	int n, a, d;
	int k, i;
	long q;
	long sum;

	scanf("%d", &t);
	k = 0;
	while (k++ < t) {
		scanf("%d %d %d", &n, &a, &d);

		q = 0;
		i = 0;
		while (i < n) {
			q += i;
			i++;
		}
		sum = a * n + d * q;
		printf("%ld\n", sum);
	}

	return 0;
}
