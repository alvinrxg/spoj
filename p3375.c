/* http://www.spoj.pl/problems/STAMPS/ */

#include <stdio.h>

void quicksorts(int s[], int l, int r)
{
	int i, j;
	int middle;
	int key;
	int tmp;

	i = l;
	j = r;
	middle = (i + j) / 2;
	key = s[middle];
	while (i < j) {
		for (; (i < r) && (s[i] > key); i++);
		for (; (j > l) && (s[j] < key); j--);
		if (i <= j) {
			tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < r)
		quicksorts(s, i, r);
	if (j > l)
		quicksorts(s, l, j);
}

int main()
{
	int t;
	long needs;
	long borrows;
	int friends;
	int stamps[1000];
	int k, i, j;

	scanf("%d", &t);
	k = 0;
	while (k++ < t) {
		printf("Scenario #%d:\n", k);

		scanf("%ld %d", &needs, &friends);
		i = 0;
		while (i < friends) {
			scanf("%d", &stamps[i]);
			i++;
		}
		quicksorts(stamps, 0, i - 1);

		borrows = 0;
		j = 0;
		while (borrows < needs && j < i) {
			borrows += stamps[j];
			j++;
		}

		if (borrows >= needs && j <= i) {
			printf("%d\n\n", j);
		}
		else {
			printf("impossible\n\n");
		}
	}

	return 0;
}
