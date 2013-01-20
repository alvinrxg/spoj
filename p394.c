/* http://www.spoj.pl/problems/ACODE/ */

#include <stdio.h>
#include <string.h>

char str[5001];
int len;
long long n;

long long hash[92];

void init_hash()
{
	int i = 0;
	hash[1] = 1;
	hash[2] = 2;
	for (i = 3; i < 92; i++) {
		hash[i] = hash[i - 1] + hash[i - 2];
	}
}

int main()
{
	int i;
	int tmp, t;
	long long n;

	init_hash();
	while (scanf("%s", str) != EOF) {
		if (str[0] == 48)
			break;
		len = strlen(str);
		n = 1;
		t = 1;
		for (i = 0; i < len - 1; i++) {
			if (str[i] == 48)
				continue;
			if ((str[i + 1] == 48) || (str[i + 2] == 48)) {
				n *= hash[t];
				t = 1;
				continue;
			}


			tmp = (str[i] - 48) * 10 + (str[i + 1] - 48);
			if (tmp > 26) {
				n *= hash[t];
				t = 1;
				continue;
			}
			t++;
		}
		n *= hash[t];
		printf ("%lld\n", n);
	}

	return 0;
}
