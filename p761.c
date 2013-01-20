#include <stdio.h>

char g[50][51];
int h, w, n;

void prints()
{
	int i;
	for(i = 0; i < h; i++)
		printf("%s\n", g[i]);
}

int func(int x, int y)
{
	if(g[x][y] == '.') {
		
	}
}

int main()
{
	int t;
	int i;
	while(t--) {
		scanf("%d %d %d", &h, &w, &n);
		for(i = 0; i < h; i++)
			scanf("%s", g[i]);
		if(func()) {
			printf("Y\n");
			prints(0, 0);
		}
		else
			printf("N\n");
	}
	return 0;
}
