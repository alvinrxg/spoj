/* http://www.spoj.pl/problems/LASTDIG/ */

#include <stdio.h>

int main()
{
	int t;
	int a;
	long b;
	long pows[10];

	int k, i;

	scanf("%d", &t);
	k = 0;
	while (k++ < t) {
		scanf("%d %ld", &a, &b);
		if (b == 0) {
			printf("1\n");
		}
		else if (a == 0 || a == 1) {
			printf("%d\n", a);
		}
		else {
			pows[0] = a;
// printf("\t%ld\n", pows[0]);
			for (i = 1; i < b; i++) {
				pows[i] = pows[i - 1] * a;
// printf("\t%ld\n", pows[i]);
// printf("\t\t\t%ld\t%ld\n", pows[i] % 10, pows[0] % 10);
				if (pows[i] % 10 == pows[0] % 10)
					break;
			}
// printf("i = %d\n", i);
			printf("%ld\n", pows[(b - 1) % i] % 10);
		}
	}

	return 0;
}
