/* http://www.spoj.pl/problems/HUBULLU/ */
/*********************************************************************
 * analyse some test cases...
 ********************************************************************/

#include <stdio.h>

int main()
{
	int t;
	long n;
	int who_first;
	int k;

	scanf("%d", &t);
	k = 0;
	while(k++ < t) {
		scanf("%ld %d", &n, &who_first);
		if (who_first)
			printf("Pagfloyd wins.\n");
		else
			printf("Airborne wins.\n");
	}
	return 0;
}
