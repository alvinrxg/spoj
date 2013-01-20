#include <stdio.h>

int main()
{
	int n;
	int m;
	char str[81];
	int i;

	scanf("%d", &n);
	i = 0;
	while (i++ < n) {
		scanf("%d %s", &m, str);
		str[m-1] = 0;
		printf("%d %s%s\n", i, str, str+m);
	}

	return 0;
}
