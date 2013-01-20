/* http://www.spoj.pl/problems/HELLOKIT/ */

#include <stdio.h>
#include <string.h>

int main()
{
	char str[1024];
	int n;
	int len;
	int max;
	int i, j;

	while (scanf("%s ", str) != EOF) {
		if (str[0] == '.')
			break;
		scanf("%d",  &n);
		len = strlen(str);
		max = len * n;
		for (j = 0; j < len; j++) {
			for (i = 0; i < max; i++) {
				printf("%c", str[(i + j) % len]);
			}
			printf("\n");
		}
		getchar(); // flush the blank space
	}
	return 0;
}
