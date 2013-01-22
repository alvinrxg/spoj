/* http://www.spoj.pl/problems/BITMAP/ */

/* bfs...
 * already better, but still TLE... */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int n, m;
char bitmap[182][183];
int distance[182][182];


void calc_dist(int x, int y)
{
	int l;
	int i, j;
	int f = 1;

	if (y == 0 && x) {
		l = distance[x - 1][0] - 1;
	}
	else if (y) {
		l = distance[x][y - 1] - 1;
	}
	else {
		l = 1;
	}
	do {
		for (i = 0; i <= l; i++) {
			j = l - i;
			// 4 directions
			if (	   (i + x < n  && j + y < m  && bitmap[x + i][y + j] == '1')
				|| (i + x < n  && y - j >= 0 && bitmap[x + i][y - j] == '1')
				|| (x - i >= 0 && j + y < m  && bitmap[x - i][y + j] == '1')
				|| (x - i >= 0 && y - j >= 0 && bitmap[x - i][y - j] == '1'))
			{
				distance[x][y] = l;
				f = 0;
				break;
			}
		}

	} while (f && ++l);
}

void calc()
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (bitmap[i][j] == '1')
				distance[i][j] = 0;
			else
				calc_dist(i, j);
		}
	}
}

void prints()
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (j == 0) {
				printf("%d", distance[i][j]);
			}
			else
				printf(" %d", distance[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int t;
	int i;

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%s", bitmap[i]);
		calc();
		prints();
	}

	return 0;
}
