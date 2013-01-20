/* http://www.spoj.pl/problems/STPAR/ */
/*
 * first output the new queue to a array,
 * then check if it is ascending order
 * */


#include <stdio.h>

int check(int s[], int x)
{
	int i;
	int fail;
	fail = 0;
	i = 0;
	while (i < x - 1) {
		if (s[i] > s[i + 1]) {
			fail++;
			break;
		}
		i++;
	}
	return fail;
}

int main()
{
	int n;
	int trucks[1000];
	int new_trucks[1000];
	int stack[1000];
	int i, j, k;

	while (scanf("%d", &n) != EOF) {
		if (n == 0)
			break;

		for (i = 0; i < n; i++) {
			scanf("%d", &trucks[i]);
		}

		j = -1;
		i = k = 0;
		while (i < n - 1) {
			if (j >= 0 && trucks[i] <= stack[j] && trucks[i] <= trucks[i + 1])
				new_trucks[k++] = trucks[i];
			else if (j >= 0 && trucks[i] > stack[j]) {
				new_trucks[k++] = stack[j--];
				continue;
			}
			else if (trucks[i] > trucks[i + 1])
				stack[++j] = trucks[i];
			else
				new_trucks[k++] = trucks[i];
			i++;
		}
		while (j >= 0) {
			if (i < n && trucks[i] < stack[j]) {
				new_trucks[k++] = trucks[i];
				i++;
			}
			else
				new_trucks[k++] = stack[j--];
		}
		if (i < n)
			new_trucks[k++] = trucks[i];

		j = check(new_trucks, k);
		if (j)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}
