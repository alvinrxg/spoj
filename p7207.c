/* http://www.spoj.pl/problems/ALCHE/ */


#include <stdio.h>

int main()
{
	long I, W;
	int a, b;

	while (scanf("%ld %ld", &I, &W) != EOF) {
		if (I == -1 && W == -1)
			break;
		if (I / 1000 == W / 37) {
			a = I % 1000;
			b = W % 37;
			if ((a == 0 && b == 0) ||
					(float)a / b == (float)1000 / 37) {
				printf("Y\n");
			}
			else
				printf("N\n");
		}
		else
			printf("N\n");
	}
	return 0;
}
