/* http://www.spoj.pl/problems/EIGHTS/ */

/*******************************************************************************
 * 192
 * 442
 * 692
 * 942
 ******************************************************************************/

#include <stdio.h>
int main()
{
	long t;
	long long k;
	long long test1, test2;
	long long cache[4] = {192, 442, 692, 942};
	long long n;
	long j;

	scanf("%ld", &t);
	j = 0;
	while (j++ < t) {
		scanf("%lld", &k);
		k--;
		test1 = k / 4;
		test2 = k % 4;
		n = test1 * 1000 + cache[test2];

		printf("%lld\n", n);
	}

	return 0;
}
