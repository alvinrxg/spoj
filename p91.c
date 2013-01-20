/* http://www.spoj.pl/problems/TWOSQRS/ */

#include <stdio.h>
#include <math.h>

int calc(long long n)
{
	int rt;		/* return 1 if yes, else 0 */
	long long a, b, tmp1, tmp2;
	long long m = sqrt(n) + 1;

	rt = 0;
	b = m;
	for (a = 0; a < m; a++) {
		tmp1 = a * a;
		for (; b >= 0; b--) {
			tmp2 = tmp1 + b * b;
			if (tmp2 == n) {
				rt = 1;
				break;
			}
			else if (tmp2 < n) {
				break;
			}
		}
		if (rt)
			break;
	}

	return rt;
}

int main()
{
	int c;
	long long n;

	scanf("%d", &c);
	while (c--) {
		scanf("%lld", &n);
		if (calc(n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}


