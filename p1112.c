#include <stdio.h>

int main()
{
	int n;
	int x, y;
	int i;
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);

		if(x == y || x == (y + 2)) {
			if(!(x & 1))
				printf("%d\n", x<<1);
			else
				printf("%d\n", (x<<1) - 1);
		}
		else
			printf("No Number\n");
	}
	return 0;
}
