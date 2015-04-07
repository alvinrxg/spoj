// http://www.spoj.com/problems/HPYNOS/
// calc brute?

#include <stdio.h>

int find_same(long array[], long num, long length)
{
	long i;
	int rt = 0;

	i = 0;
	while (i < length) {
		if (array[i] == num) {
			rt = 1;
			break;
		}
		i++;
	}

	return rt;
}

int main()
{
	long array[100];
	long n, j;
	long num, tmp_i, tmp;

	scanf("%ld", &n);


	for (j = 0; j < 100; j++) {
		if (j == 0)
			tmp_i = n;
		else
			tmp_i = array[j - 1];

		num = 0;
		while (tmp_i > 0) {
			tmp = tmp_i % 10;
			num += tmp * tmp;
			tmp_i /= 10;
		}
		array[j] = num;
		if (num == 1 || find_same(array, num, j) == 1) {
			break;
		}
	}

	if (array[j] == 1) {
		printf("%ld\n", j+1);
	}
	else {
		printf("-1\n");
	}

	return 0;
}
