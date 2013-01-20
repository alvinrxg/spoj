/* http://www.spoj.pl/problems/CANDY/ */

#include <stdio.h>

int main()
{
	long n;
	int candy[10000];
	long sum;
	long que;
	long move;
	long i;

	while (1) {
		scanf("%ld", &n);
		if (n == -1)
			break;
		sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &candy[i]);
			sum += candy[i];
		}
		if (sum % n == 0) {
			que = sum / n;
			move = 0;
			for (i = 0; i < n; i++) {
				if (candy[i] > que) {
					move += candy[i] - que;
				}
			}
			printf("%ld\n", move);
		}
		else {
			printf("-1\n");
		}

	}
	return 0;
}
