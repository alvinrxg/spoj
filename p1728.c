// http://www.spoj.com/problems/CPRMT/
#include <stdio.h>
#include <string.h>

int check(char str[], char c)
{
	int i = 0;
	int rt = 0;
	while (i < 1000) {
		if (str[i] == c) {
			rt++;
		}
		else if (str[i] == 0) {
			break;
		}
		i++;
	}

	return rt;
}


int main()
{
	char a[1001];
	char b[1001];
	char c[1001];
	int i, j;

	while( scanf("%s\n%s", a, b) != EOF ) {
		i = 0;
		j = 0;
		while (i < 26) {
			char ccc = 'a' + i;
			int al = check(a, ccc);
			int bl = check(b, ccc);
			int l = al < bl ? al: bl;

			int xx = 0;
			while (xx < l) {
				c[j++] = ccc;
				xx++;
			}

			i++;
		}
		c[j] = 0;
		printf("%s\n", c);
	}
}
