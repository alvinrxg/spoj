/* http://www.spoj.pl/problems/EXFOR/ */
/*
 * input 4 one or 8 one, return 0; otherwise 1;
 */

#include <stdio.h>

int main()
{
	int t;
	int x;
	int nums;
	int k;
	int i;

	scanf("%d", &t);
	k = 0;
	while (k++ < t) {
		i = 0;
		nums = 0;
		while (i < 10) {
			scanf("%d", &x);
			if (x)
				nums++;
			i++;
		}
		if (nums % 4 == 0)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
