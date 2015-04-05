// http://www.spoj.com/problems/BITMAP/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct POINT {
	int x;
	int y;
} POINT;

int targetMap[182][182];

int calc(char matrix[182][183], int m, int n)
{
	POINT pointList[33124];
	int pointNo;
	int i, j, k;

	pointNo = 0;
	i = 0;
	while (i < m) {
		j = 0;
		while (j < n) {
			if (matrix[i][j] == '1') {
				POINT p = {i, j};
				// pointList[pointNo].x = i;
				// pointList[pointNo].y = j;
				pointList[pointNo] = p;
				pointNo ++;
			}
			j++;
		}
		i++;
	}

	// i = 0;
	// while (i < pointNo) {
		// printf("point: %d %d\n", pointList[i].x, pointList[i].y);
		// i++;
	// }
	// return;


	i = 0;
	while (i < m) {
		j = 0;
		while (j < n) {
			if (matrix[i][j] == '0') {
				for (k = 0; k < pointNo; k++) {
					int dist = abs(i - pointList[k].x) + abs(j - pointList[k].y);
					if (dist < targetMap[i][j]) {
						targetMap[i][j] = dist;
					}
				}
			}
			else {
				targetMap[i][j] = 0;
			}
			j++;
		}
		i++;
	}




	i = 0;
	while (i < m) {
		j = 0;
		while (j < n) {
			printf ("%d ", targetMap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	return 0;
}

int main ()
{
	int t;
	int i, j;
	int m, n;
	char matrix[182][183];

	scanf("%d", &t);
	i = 0;
	while (i++ < t) {
		scanf("%d %d", &m, &n);

		j = 0;
		while(j < m) {
			scanf("%s", matrix[j]);

			j++;
		}

		int a,b;
		a = 0;
		while (a < 182) {
			b = 0;
			while (b < 182) {
				targetMap[a][b] = INT_MAX;
				b++;
			}
			a++;
		}

		calc(matrix, m, n);
	}





	return 0;
}
