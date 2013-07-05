/* http://www.spoj.com/problems/MAXLN/ */
#include <stdio.h>

int main()
{
	int t, i;
	double s;
	long r;

	scanf("%d", &t);

	i = 1;
	while(i <= t) {
		scanf("%ld", &r);
		s = (double)4 * r * r + 0.25;

		printf("Case %d: %.2lf\n", i, s);

		i++;
	}

	return 0;
}
