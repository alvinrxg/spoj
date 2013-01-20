#include <stdio.h>

int rev(int n)
{
	int tmp;
	tmp = 0;
	while(n) {
		tmp = tmp * 10 + n % 10;
		n /= 10;
	}
	return tmp;
}
int main()
{
	int n, i;
	int n1, n2;
	int sum;

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &n1, &n2);

		n1 = rev(n1);
		n2 = rev(n2);
		sum = n1 + n2;
		sum = rev(sum);

		printf("%d\n", sum);
	}
	return 0;
}
