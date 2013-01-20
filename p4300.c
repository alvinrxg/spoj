/* http://www.spoj.pl/problems/AE00/ */

#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	int i;
	int sum;

	while (scanf("%d", &n) != EOF) {
		sum = 0;
		for (i = 1; i <= sqrt(n); i++) {
			sum += n / i - i + 1;
		}
		printf ("%d\n", sum);
	}
	return 0;
}
