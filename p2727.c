/* http://www.spoj.pl/problems/ARMY/ */

#include <stdio.h>

int main()
{
	unsigned int t;
	unsigned int ng, nm;
	unsigned int g, m, tmp;
	unsigned int k;
	unsigned int i;

	scanf("%d", &t);
	k = 0;
	while(k++ < t) {
		scanf("%d %d", &ng, &nm);
		i = 0;
		g = 0;
		while (i++ < ng) {
			scanf("%d", &tmp);
			if (g < tmp)
				g = tmp;
		}
		i = 0;
		m = 0;
		while (i++ < nm) {
			scanf("%d", &tmp);
			if (m < tmp)
				m = tmp;
		}

		if (g < m)
			printf("MechaGodzilla\n");
		else
			printf("Godzilla\n");
	}
	return 0;
}
