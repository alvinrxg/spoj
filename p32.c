/* http://www.spoj.pl/problems/NHAY/ */
/*
 * fgets(...)
 *
 * man 3 string
 * */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int len;
	char *needle, *haystack;

	while (scanf("%d", &len) == EOF) {
		if (needle) {
			free(needle);
			needle = malloc(len * sizeof(char));
		}
		if (haystack) {
			free(haystack);
			haystack = malloc(2 * len * sizeof(char));
		}
		fgets(needle, len, stdin);
		fgets(haystack, len * 2, stdin);
		// ...
	}
	return 0;
}
