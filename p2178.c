/* http://www.spoj.pl/problems/OFFSIDE/ */

#include <stdio.h>

void sorts(int x[], int n)
{
	int i, j;
	int tmp;
	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			if (x[j] > x[j + 1]) {
				tmp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int a, d;
	int b[12], c[12];
	int i;

	while (scanf("%d %d", &a, &d) != EOF) {
		if (a == 0 && d == 0)
			break;
		i = 0;
		while (i < a) {
			scanf("%d", &b[i]);
			i++;
		}
		i = 0;
		while (i < d) {
			scanf("%d", &c[i]);
			i++;
		}
		sorts(b, a);
		sorts(c, d);

		if (b[0] < c[1])
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
