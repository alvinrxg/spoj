/* http://www.spoj.com/problems/LASTDIG2/ */
#include <stdio.h>
#include <string.h>
int last[10][4]= {
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{2, 4, 8, 6},
	{3, 9, 7, 1},
	{4, 6, 4, 6},
	{5, 5, 5, 5},
	{6, 6, 6, 6},
	{7, 9, 3, 1},
	{8, 4, 2, 6},
	{9, 1, 9, 1}
};
int last_a(char a[])
{
	int i;
	i = 1001;
	while((a[i] < '0' || a[i] > '9') && i >= 0) {
		i--;
	}
	return (a[i] - '0');
}
int main()
{
	int t;
	char a[1002];
	int base;
	long long b;
	int index;
	scanf("%d", &t);
	while(t--) {
		memset(a, 0, sizeof(a));
		scanf("%s %lld", a, &b);

		if (b == 0) {
			printf("1\n");
			continue;
		}
		base = last_a(a);
		index = (b - 1) % 4;
		printf("%d\n", last[base][index]);
	}
}
