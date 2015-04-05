// http://www.spoj.com/problems/CRDS/

/*  1             2             3            ...
 * (0 + 2 * 1) + (1 + 2 * 2) + (2 + 2 * 3) + ...
 *
 */

#include <stdio.h>

long long calc(long long n)
{
	long long sum;
	sum = 0;

	sum += ( n * (n - 1) / 2 )
		+
		( 2 * (n * (2 + (n - 1))) / 2 );

	if (sum >= 1000007) {
		sum %= 1000007;
	}

	return sum;
}

int main()
{
	int t, i;
	long long n;

	scanf("%d", &t);
	i = 0;
	while (i < t) {
		scanf("%lld", &n);
		printf("%lld\n", calc(n));

		i++;
	}

	return 0;
}
