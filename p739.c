/* http://www.spoj.pl/problems/NEG2/ */
/* http://blog.csdn.net/yming0221/article/details/6159075 */

#include <stdio.h>

int main()
{
	int base[34];
	long n;
	int i;

	while (scanf("%ld", &n) != EOF) {
		if (n == 0) {
			printf("0\n");
			continue;
		}

		i = 0;
		while (n) {
			if (n % -2) {
				base[i] = 1;
				n = (n - 1) / (-2);
			}
			else {
				base[i] = 0;
				n = n / (-2);
			}
			i++;
		}
		i--;
		while (i >= 0) {
			printf("%d", base[i]);
			i--;
		}
		printf("\n");

	}
	return 0;
}
