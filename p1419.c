/* http://www.spoj.pl/problems/NGM/ */

#include <stdio.h>

int main()
{
	long x;

	scanf("%ld", &x);
	if (x % 10) {
		printf("1\n");
		printf("%d\n", x % 10);
	}
	else {
		printf("2\n");
	}
	return 0;
}
