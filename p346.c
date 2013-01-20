/* http://www.spoj.pl/problems/COINS/ */


#include <stdio.h>

#define NUM 100000

long long s[NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};


long long calc(long long n)
{
	long long t, rt;
	long long sum;
	long i;

	if (n == 0) {
		return 0;
	}
	else if (n < NUM) {
		if (s[n]) {
			// do nothing
			// return s[n];
		}
		else {
			t = calc(n / 2) + calc(n / 3) + calc(n / 4);
			if (t < n)
				s[n] = n;
			else
				s[n] = t;
		}
		rt = s[n];
	}
	else {
		t = calc(n / 2) + calc(n / 3) + calc(n / 4);
		if (t < n)
			rt = n;
		else
			rt = t;
	}

	return rt;
}

int main()
{
	long long n;

	while (scanf("%lld", &n) != EOF) {
		printf("%lld\n", calc(n));
	}
	return 0;
}
