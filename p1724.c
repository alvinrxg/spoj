// http://www.spoj.com/problems/TRICOUNT/
////////// TLE //////////
// O(n^2)
//
// l == level
// s == sum
// a == start_number
// b == end_number
// m == numbers

#include <stdio.h>
long long cc(long long n)
{
	long long l, s, z, zz, a, b;
	s = 0;
	z = 0;
	for (l = 1; l <= n; l ++) {
		if (l <= n / 2) {
			s += l * (1 + l) / 2;
			a = l + 2;
			b = n + n - l * 3 + 2;
			if (a == b) {
				s += a;
			}
			else {
				s += ((b - a) / 2 + 1) * (a + b) / 2;
			}
		}
		else {
			zz = l - n / 2;
			s += z + zz;
			z += zz;
		}
	}
	return s;
}
int main()
{
	long long t, i, n;
	scanf("%lld", &t);
	i = 0;
	while (i < t) {
		scanf("%lld", &n);
		printf("%lld\n", cc(n));
		i++;
	}
	return 0;
}
