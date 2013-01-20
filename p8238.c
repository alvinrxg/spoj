#include <stdio.h>
#include <math.h>

long prime[100000];
int x;

void gen_pri()
{
	long i, j;
	long q;
	for(i = 2; i <= 1000000; i++) {
		q = (long) sqrt(i);
		for(j = 2; j <= q; j++) {
			if(i % j == 0) {
				break;
			}
		}
		if(j > q)
			prime[x++] = i;
	}
}

int check(long m, int n)
{
	int i;
	int num;
	num = 0;
	for(i = 0; i < x; i++) {
		if(m % prime[i] == 0)
		num++;
		if(num > n)
			break;
	}
	if(num == n)
		return 1;
	else
		return 0;
}

int main()
{
	int t;
	long a, b;
	int n;
	long num;
	int i;
	x = 0;
	gen_pri();

	scanf("%d", &t);
	while(t--) {
		scanf("%ld %ld %d", &a, &b, &n);

		if(n == 0) {
			printf("1\n");
			continue;
		}
		num = 0;
		for(i = a; i <= b; i++) {
			if (check(i, n))
				num++;
		}
		printf("%ld\n", num);
	}
	return 0;
}
