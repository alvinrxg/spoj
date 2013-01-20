#include <stdio.h>
#include <string.h>

char str[201];

int main()
{
	int c, l;
	int i, j, k;
	while(scanf("%d", &c) != EOF && c != 0) {
		scanf("%s", str);
		l = strlen(str);

		for(i = 0; i < c; i++) {
			for(j = 0; j < l / c; j++) {
				if(j % 2 == 1)
					k = c * (j + 1) - 1 - i;
				else
					k = c * j + i;
				printf("%c", str[k]);
			}
		}
		printf("\n");
	}
	return 0;
}
