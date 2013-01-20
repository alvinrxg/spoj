#include <stdio.h>

int main()
{
	long number, n;
	long zero;
	long i;
	long tmp, m;

	scanf("%ld", &number);
	for (i = 0; i < number; i++) {
		scanf ("%ld", &n);

		zero = 0;
		tmp = n;

		zero += tmp / 5;
		m = zero;
		while (m >= 5) {
			zero += m / 5;
			m /= 5;
		}


		printf("%ld\n", zero);
	}

	return 0;
}

