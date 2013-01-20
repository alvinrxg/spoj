/* http://www.spoj.pl/problems/FAMILYP/ */

#include <stdio.h>

long cache[1500];
int cache_n = 0;

void generate(long n)
{
	long i;
	i = cache_n + 1;
	while (1) {
		cache[i] = i * (i - 1) / 2 + 1;
		if (cache[i] > n)
			break;
		i++;
	}
	cache_n = i;
}

int get_level(long n)
{
	int i;
	for (i = 0; i < cache_n; i++) {
		if (n >= cache[i] && n < cache[i + 1])
			break;
	}
	return i;
}

int main()
{
	long n;
	int level;
	char c;
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;
	cache_n = 3;

	while (scanf("%ld", &n) != EOF) {
		if(n > cache[cache_n]) {
			generate(n);
		}
		level = get_level(n);
		c = level % 26 + 'A' - 1;

		printf("TERM %ld IS %c\n", n, c);
	}
	return 0;
}
