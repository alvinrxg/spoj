/* http://www.spoj.pl/problems/MARBLES/ */
/* well, don't understand why must n-1, k-1 (n-k-1+1) ... */
/* TLE */

#include <stdio.h>

long long kkk[1000001];
long long calc(long long n, long long k)
{
	long long big, small;
	long long rt;
	long long t, n1, k1;
	long long i;

	rt = 1;
	t = n - k;
	n1 = n - 1;
	k1 = k - 1;

	big = t > k1 ? k1 : t;
	small = t < k1 ? k1 : t;

	while(n1 > big) {
		for (i = small; i > 1; i--) {
			if (kkk[i] == 0 && n1 % i == 0) {
				kkk[i] = 1;
				break;
			}
		}
		if (i == 1) {
			rt *= n1;
		}
		else {
			rt *= (n1 / i);
		}
		n1--;
	}
	for (i = small; i > 1; i--) {
		if (kkk[i] == 0) {
			rt /= i;
		}
		else {
			kkk[i] = 0;
		}
	}
	return rt;
}

int main()
{
	int t;
	long long n, k;

	for (n = 0; n < 1000001; n++) {
		kkk[n] = 0;
	}

	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld", &n, &k);
		printf("%lld\n", calc(n, k));
	}
	return 0;
}
