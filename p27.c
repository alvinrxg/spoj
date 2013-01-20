/* http://www.spoj.pl/problems/SBANK/ */
/*	TLE	*/
/*	sorts() has problem	*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sorts(char *arr[], long l, long r)
{
	char *tmp = arr[l];
	long p = l;
	long i = l;
	long j = r;

	while (i <= j) {
		while (strcmp(arr[j], tmp) >= 0 && j >= p)
			j--;
		if (j >= p) {
			arr[p] = arr[j];
			p = j;
		}
		while (strcmp(tmp, arr[i]) >= 0 && i <= p)
			i++;
		if (i <= p) {
			arr[p] = arr[i];
			p = i;
		}
	}
	arr[p] = tmp;
	if (p - l> 1)
		sorts(arr, l, p - 1);
	if (r - p > 1)
		sorts(arr, p + 1, r);

}

void counts(char *arr[], int repeats[], long n)
{
	long x;
	long t;
	x = 0;
	while (x < n) {
		if (repeats[x] == 0) {
			repeats[x]++;
			t = x + 1;
			while (t < n) {
				if (repeats[t] >= 0 && strcmp(arr[x],
							arr[t]) == 0) {
					repeats[x]++;
					repeats[t] = -1;
				}
				t++;
			}
		}
		if (repeats[x] > 0) {
			printf("%s %d\n", arr[x], repeats[x]);
		}
		x++;
	}
}

int main()
{

	char *arr[100000];
	int repeats[100000] = {0};
	int t;
	long n;
	int k;
	long kk;

	arr[0] = malloc(sizeof(char) * 32 * 100000);
	n = 0;
	while (++n < 100000) {
		arr[n] = arr[0] + n * 32 * sizeof(char);
	}
	scanf("%d", &t);
	k = 0;
	while (k++ < t) {
		scanf("%ld", &n);
		getchar();

		kk = 0;
		while (kk < n) {
			gets(arr[kk]);
			kk++;
		}

		sorts(arr, 0, n - 1);
		counts(arr, repeats, n);

		printf("\n");
	}

	return 0;
}
