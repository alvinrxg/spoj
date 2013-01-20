/* http://www.spoj.pl/problems/ACPC10A/ */

#include <stdio.h>

int main()
{
	int a1, a2, a3;
	long next;
	int test1, test2;

	while (scanf("%d %d %d", &a1, &a2, &a3) != EOF) {
		if (a1 == 0 && a2 == 0 && a3 == 0)
			break;
		test1 = a2 - a1;
		test2 = a3 - a2;
		if (test1 == test2)
			printf("AP %lld\n", (long long)(a3 + test1));
		else {
			printf("GP %lld\n", (long long)a3 * (long long)a2 / (long long)a1);
		}

	}
	return 0;
}
