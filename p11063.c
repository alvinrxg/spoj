// http://www.spoj.com/problems/AP2/

#include <stdio.h>

void calc(long long a, long long b, long long sum)
{
	long long num_count;
	long long diff;
	long long num;
	long long i;

	num_count = sum / (a + b) * 2;
	if (sum % (a + b) != 0) {
		num_count += 1;
	}

	diff = (b - a) / (num_count - 5);

	printf("%lld\n", num_count);

	// num to print
	num = a - diff * 2;
	i = 0;
	while (i < num_count - 1) {
		printf("%lld ", num);
		num += diff;
		i++;
	}
	printf("%lld\n", num);
}

int main()
{
	long long t, i;
	long long a, b, sum;


	scanf("%lld", &t);
	i = 0;
	while (i < t) {
		scanf("%lld %lld %lld", &a, &b, &sum);
		calc(a, b, sum);

		i++;
	}
	return 0;
}
