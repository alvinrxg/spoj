/* http://www.spoj.pl/problems/GNY07B/ */

#include <stdio.h>

int main()
{
	int n, k;
	double val, res;
	char unit[3];

	scanf("%d", &n);
	k = 0;
	while (k++ < n) {
		scanf("%lf %s", &val, unit);
		if (unit[0] == 'k') {
			res = val * 2.2046;
			printf("%d %.4lf lb\n", k, res);
		}
		else if (unit[0] == 'g') {
			res = val * 3.7854;
			printf("%d %.4lf l\n", k, res);
		}
		else if (unit[0] == 'l' && unit[1] == 0) {
			res = val * 0.2642;
			printf("%d %.4lf g\n", k, res);
		}
		else {
			res = val * 0.4536;
			printf("%d %.4lf kg\n", k, res);
		}
	}

	return 0;
}
