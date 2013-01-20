#include <stdio.h>

int grids[101];

void inits()
{
	int i;
	grids[1] = 1;
	for (i = 2; i <= 100; i++) {
		grids[i] = grids[i - 1] + i * i;
	}
}
int main()
{
	int n;

	inits();
	while(1) {
		scanf("%d", &n);
		if (!n)
			break;
		printf("%d\n", grids[n]);
	}

	return 0;
}
