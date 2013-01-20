/* http://www.spoj.pl/problems/ANARC08E/ */

#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;

	while (scanf("%d %d", &a, &b) != EOF) {
		if (a == -1 || b == -1)
			break;
		c = a + b;
		if (a == 1 || b == 1) {
			printf("%d+%d=%d\n", a, b, c);
		}
		else
			printf("%d+%d!=%d\n", a, b, c);
	}
	return 0;
}
