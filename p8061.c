#include <stdio.h>
#include <limits.h>

int k, n;
long height[20000];

void swap(long *a, long *b)
{
	long tmp;
	tmp = *a; *a = *b; *b = tmp;
}

void quick_sort(int left, int right)
{
	int i = left + 1, j = right;
	long key = height[left];

	if (left >= right) return;

	while (1) {
		while (height[j] > key) j--;
		while (height[i] < key&&i<j) i++;
		if(i >= j)
			break;
		swap(&height[i],&height[j]);
		if(height[i]==key)j--;
		else  i++;
	}

	swap(&height[left],&height[j]);

	if(left  < i - 1)
		quick_sort(left, i - 1);
	if(j + 1 < right)
		quick_sort(j + 1 , right);

}


long check()
{
	long min = LONG_MAX;
	long tmp;
	int i = 0;
	int max = n - k + 1;
	while (i < max) {
		tmp = height[i + k - 1] - height[i];
		if (tmp < min) {
			min = tmp;
		}
		i++;
	}
	return min;
}


int main ()
{
	int t;
	int i;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		i = 0;
		while (i < n) {
			scanf("%ld", &height[i]);
			i++;
		}

		quick_sort(0, n- 1);


		printf("%ld\n", check());
	}
	return 0;
}
