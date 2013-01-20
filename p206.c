/* http://www.spoj.pl/problems/BITMAP/ */
/*		TLE		*/

#include <stdio.h>
#include <stdlib.h>

void calc(char matrix[][183], int new[][183], int n, int m)
{
	int i, j;
	int x, y, k;
	int len;

	i = 0;
	while (i < n) {
		j = 0;
		while (j < m) {
			if (matrix[i][j] == '1') {
				new[i][j] = 0;
			}
			else {
				k = 0;
				while(++k) {
					new[i][j] = 0;
					y = 0;
					while (y <= k) {
						x = k - y;
						if (i + x < n) {
							if (j + y < m) {
								if (matrix[i + x][j + y] == '1') {
									new[i][j] = k;
									break;
								}
							}
							if (j - y >= 0) {
								if (matrix[i + x][j - y] == '1') {
									new[i][j] = k;
									break;
								}
							}
						}
						if(new[i][j] == 0) {
							if (i - x >= 0) {
								if (j + y < m) {
									if (matrix[i - x][j + y] == '1') {
										new[i][j] = k;
										break;
									}
								}
								if (j - y >= 0) {
									if (matrix[i - x][j - y] == '1') {
										new[i][j] = k;
										break;
									}
								}
							}
						}

						y++;
					}
					if (new[i][j])
						break;
				}
			}
			j++;
		}
		i++;
	}
}

void prints(int new[][183], int n, int m)
{
	int i, j;
	i = 0;
	while (i < n) {
		j = 0;
		while (j < m - 1) {
			printf("%d ", new[i][j]);
			j++;
		}
		printf("%d\n", new[i][j]);
		i++;
	}
}
int main()
{
	int t;
	int n, m;
	char matrix[182][183];
	int new[182][183];
	int i, j;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		i = 0;
		while (i < n) {
			scanf("%s", matrix[i]);
			i++;
		}

		calc(matrix, new, n, m);
		prints(new, n, m);
	}

	return 0;
}
