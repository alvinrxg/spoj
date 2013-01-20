#include <stdio.h>

int a[1000], b[1000];

void sorts(int n)
{
	int i, j;
	int tmp;
	for (i = 0; i < n; i++) {
		for (j = 1; j < n - i; j++) {
			if (a[j - 1] > a[j]) {
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
			if (b[j - 1] > b[j]) {
				tmp = b[j];
				b[j] = b[j - 1];
				b[j - 1] = tmp;
			}
		}
	}
}

int main()
{
	int t;
	int n;
	int k;
	int i;
	long sum;

	scanf("%d", &t);
	k = 0;
	while(k++ < t) {
		scanf("%d", &n);
		i = 0;
		while (i < n) {
			scanf("%d", &a[i]);
			i++;
		}
		i = 0;
		while (i < n) {
			scanf("%d", &b[i]);
			i++;
		}

		sorts(n);

		sum = 0;
		for (i = 0; i < n; i++) {
			sum += a[i] * b[i];
		}
		printf("%ld\n", sum);
	}

	return 0;
}
