// http://www.spoj.com/problems/OLOLO/

#include <stdio.h>

int main()
{
	long n, i;
	long calc, p;


	scanf("%ld", &n);
	i = 0;
	calc = 0;
	while (i < n) {
		scanf("%ld", &p);
		calc ^= p;
		i++;
	}
	printf("%ld\n", calc);


	return 0;
}
