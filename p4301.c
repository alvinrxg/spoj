/* http://www.spoj.pl/problems/AE1B/ */

#include <stdio.h>

void sorts(int a[], int n)
{
	int i, j;
	int tmp;
	for (i = n - 1; i; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}

		}
	}
}
int main()
{
	int n, k, s;
	int a[1000];
	int i;
	int j;
	long sum, min;

	while(scanf("%d %d %d", &n, &k, &s) != EOF) {
		i = 0;
		while (i < n) {
			scanf("%d", &a[i]);
			i++;
		}
		sorts(a, n);
		min = k * s;
		j = 0;
		sum = a[j];
		while (sum < min) {
			j++;
			sum += a[j];
		}
		j++;

		printf("%d\n", j);
	}

	return 0;
}
