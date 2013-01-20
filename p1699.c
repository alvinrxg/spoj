/* https://www.spoj.pl/problems/NSYSTEM/ */

#include <stdio.h>
char unit[4] = {'m', 'c', 'x', 'i'};

void add(int mcxi[], char *str) {
	int i;
	int multi;

	i = 0;
	multi = 1;
	while (*(str + i)) {
		switch (*(str + i)) {
			case 'm':
				mcxi[0] += multi;
				multi = 1;
				break;
			case 'c':
				mcxi[1] += multi;
				multi = 1;
				break;
			case 'x':
				mcxi[2] += multi;
				multi = 1;
				break;
			case 'i':
				mcxi[3] += multi;
				multi = 1;
				break;
			default:
				multi = *(str + i) - '0';
		}
		i++;
	}
}

void check_carry(int mcxi[]) {
	int i;
	i = 3;
	while (i >= 0) {
		if (mcxi[i] > 9) {
			mcxi[i] %= 10;
			mcxi[i - 1] ++;
		}
		i--;
	}
}

void putss(int mcxi[]) {
	int i;

	i = 0;
	while (i < 4) {
		switch (mcxi[i]) {
			case 0:
				break;
			case 1:
				printf("%c", unit[i]);
				break;
			default:
				printf("%d%c", mcxi[i], unit[i]);
		}
		i++;
	}
	printf("\n");
}

int main()
{
	int n;
	int mcxi[4];
	char str1[9], str2[9];
	int i;

	scanf("%d", &n);
	while (n--) {
		scanf("%s %s", str1, str2);
		for (i = 0; i < 4; i++) mcxi[i] = 0;
		add(mcxi, str1);
		add(mcxi, str2);
		check_carry(mcxi);
		putss(mcxi);
	}

	return 0;
}
