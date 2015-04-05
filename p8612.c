// http://www.spoj.com/problems/NY10A/

#include <stdio.h>

int check_seq(char c[])
{
	int index = 0;

	if (c[0] == 'H') {
		index |= 4;
	}
	if (c[1] == 'H') {
		index |= 2;
	}
	if (c[2] == 'H') {
		index |= 1;
	}

	return index;
}

void calc(char str[])
{
	int counts[8] = {0};

	int i;
	int index;
	i = 0;
	while (i < 38) {
		index = check_seq(str + i);
		counts[index] ++;
		i++;
	}

	i = 0;
	while (i < 8) {
		printf(" %d", counts[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int p, i;
	int n;
	char str[41];

	scanf("%d", &p);
	i = 0;
	while (i < p) {
		scanf("%d", &n);
		printf("%d ", n);
		scanf("%s", str);

		calc(str);

		i++;
	}



	return 0;
}
