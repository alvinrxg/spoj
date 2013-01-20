/* http://www.spoj.pl/problems/CANDY3/ */

#include <stdio.h>

int main()
{
	long t;
	long n;
	long long candy;
	long long mod;
	long k, i;

	scanf("%ld", &t);
	k = 0;
	while (k++ < t) {
		scanf("%ld", &n);
		mod = 0;
		for (i = 0; i < n; i++) {
			scanf("%lld", &candy);
			mod = (mod + candy) % n;
		}
		if (mod) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}
