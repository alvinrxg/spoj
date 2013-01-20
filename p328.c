/* http://www.spoj.pl/problems/BISHOPS/ */

#include <stdio.h>
#include <string.h>

int func(char n[], int l)
{
	int i;
	int c;
	c = 0;
	for (i = l - 1; i >= 0; i--) {
		n[i] += n[i] - 48 + c;
		if (n[i] > '9') {
			n[i] -= 10;
			c = 1;
		}
		else
			c = 0;
	}

	i = l - 1;
	n[i] -= 2;
	while (n[i] < '0' && i > 0) {
		n[i] += 10;
		n[i - 1]--;
		i--;
	}
	if (n[0] < '0') {
		if (c) {
			n[0] += 10;
			c = 0;
		}
		else {
			// it seems no need process when c == 0
		}
	}
	return c;
}

int main()
{
	char n[110];
	int len;
	int x;

	while (scanf("%s", n) != EOF) {
		len = strlen(n);
		if (len <= 1 && n[0] <= '2'){
			printf("%s\n", n);
		}
		else {
			x = func(n, len);
			if (x)
				printf("%d", x);
			printf("%s\n", n);
		}
	}
	return 0;
}
