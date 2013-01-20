/* https://www.spoj.pl/problems/TRT/ */

#include <stdio.h>

int main()
{
	int n;
	int v[2000];
	long sum;
	int i;
	int a, b;	/*begin and end of the box*/

	while (scanf("%d", &n) != EOF) {
		i = 0;
		while (i < n) {
			scanf("%d", &v[i]);
			i++;
		}
		a = 0;
		b = n - 1;
		i = 1;
		sum = 0;
		while (a <= b) {
			if (v[a] > v[b]) {
				sum += v[b] * i;

				b--;
			}
			else {
				sum += v[a] * i;
				a++;
			}
			i++;
		}
		printf("%ld\n", sum);
	}
	return 0;
}
