/* http://www.spoj.pl/problems/MIRRORED/ */

#include <stdio.h>

int main()
{
	char c[4096];
	int j;
	int len;
	int o_or_n;


	printf("Ready\n");
	while (1) {
		j = 0;
		while (c[j] = getchar()) {
			if (c[j] == 10 || c[j] == 13)
				break;
			j++;
		}
		if (c[0] == ' ' && c[1] == ' ')
			break;

		else {
			len = j;
			o_or_n = 1;
			for (j = 0; j < len / 2; j++) {
				if ((c[j] == 'q' && c[len - j - 1] == 'p') ||
						(c[j] == 'p' && c[len - j - 1] == 'q') ||
						(c[j] == 'b' && c[len - j - 1] == 'd') ||
						(c[j] == 'd' && c[len - j - 1] == 'b'))
				{
					// nothing
				}
				else {
					o_or_n = 0;
					printf ("Ordinary pair\n");
					break;
				}
			}
			if (o_or_n)
				printf ("Mirrored pair\n");

		}
	}
	return 0;
}
