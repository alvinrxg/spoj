/* https://www.spoj.pl/problems/BEENUMS/ */
/* 1	+ 6
 * 7	+ 12
 * 19	+ 24
 * 43	+ ...
 * */

#include <stdio.h>
#include <math.h>

int main()
{
	long n;
	long tmp, t;
	int flag;

	while (scanf ("%ld", &n) != EOF) {
		flag = 0;
		if (n == -1)
			break;
		if (n < 7) {
			if (n == 1)
				flag = 1;
		}
		else {
			tmp = n - 1;
			if (tmp % 6 == 0) {
				tmp /= 6;
				t = (sqrt(1 + 8 * tmp) - 1 ) / 2;
				if ((t * t + t) == 2 * tmp) {
					flag = 1;
				}
			}
		}
		if (flag)
			printf ("Y\n");
		else
			printf ("N\n");
	}
	return 0;
}
