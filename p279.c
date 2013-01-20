/* http://www.spoj.pl/problems/AGGRCOW/ */

#include <stdio.h>

int main()
{
	int t;
	long n, c;
	long pos[100000];
	int k;
	long i;

	scanf("%d", &t);
	k = 0;
	while (k++ < t) {
		scanf("%ld %ld", &n, &c);
		i = 0;
		while(i < n) {
			scanf("%ld", &pos[i]);
			i++;
		}
		
	}

	return 0;
}
