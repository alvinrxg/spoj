/* http://www.spoj.pl/problems/ABSYS/ */

#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	char str[80];
	long n[3];
	int length;
	int k, i, n_i;

	scanf("%d", &t);
	k = 0;
	while (k < t) {
		gets(str);
		if (str[0] == 0)
			continue;

		length = strlen(str);

		n[0] = n[1] = n[2] = n_i = 0;
		for (i = 0; i < length && n_i < 3; i++) {
			if (str[i] == ' ') {
				i += 2;
				n_i++;
			}
			else if (str[i] == 'm') {
				n[n_i] = -1;
				i += 6;
				// n_i++;
			}
			else if (n[n_i] >= 0){
				n[n_i] = n[n_i] * 10 + str[i] - 48;
			}
		}
		if (n[0] == -1)
			n[0] = n[2] - n[1];
		else if (n[1] == -1)
			n[1] = n[2] - n[0];
		else
			n[2] = n[0] + n[1];

		printf("%ld + %ld = %ld\n", n[0], n[1], n[2]);

		k++;
	}
	return 0;
}
