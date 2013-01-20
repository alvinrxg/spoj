/*
 * 	fail
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L (10000 * 10000)
#define S 10000

char n1[S], n2[S];
char *m;
int max;
int a, b;

void print()
{
	int i;
	for(i = max; i >= 0; i--)
		if(*(m + i))
			break;
	for(; i >= 0; i--)
		printf("%d", *(m + i));
	printf("\n");
	free(m);
}

void multi()
{
	int i, j, k;
	int inc;

	a = strlen(n1);
	b = strlen(n2);

	m = (char *) malloc(sizeof(char) * a * b + 1);

	for(i = 0; i < a; i++) {
		inc = 0;
		for(j = 0; j < b; j++) {
			if(i == 0) {
				*(m + j + i) = 0;
			}
			*(m + j + i) += (n1[a - i - 1] - 48) * (n2[b - j - 1] - 48) + inc;
			inc = *(m + j + i) / 10;
			*(m + j + i) %= 10;
		}
		if(inc) {
			max = j + i - 1;
			if(i == 0) {
				*(m + max) = 0;
			}
			*(m + max) += inc;
		}
	}

	print();
}


int main()
{
	int n, i, j;

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s %s", n1, n2);

		multi();

	}

	return 0;
}
