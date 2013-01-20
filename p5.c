/* http://www.spoj.pl/problems/PALIN/ */

#include <stdio.h>
#include <string.h>

char orig[1000001];
char palindrome[1000002];
long len;
int check_larger(long len)
{
	int rt;		/* return 0 if larger, else 1*/
	long i;

	i = 0;
	rt = 1;
	while (i < len) {
		if (orig[i] > palindrome[i + 1]) {
			rt = 1;
			break;
		}
		else if (orig[i] < palindrome[i + 1]) {
			rt = 0;
			break;
		}
		i++;
	}
	return rt;
}

int check_carry(long len)
{
	int rt;		/* return 0 if normal carry, no palindrome[0]; else 1 */
	long i;

	for (i = (len + 1) / 2; i > 0; i--) {
		if (palindrome[i] > '9') {
			palindrome[i] -= 10;
			palindrome[len - i + 1] = palindrome[i];
			palindrome[i - 1]++;
			palindrome[len - i + 2]++;
		}
	}
	if (palindrome[0] == '0')
		rt = 0;
	else
		rt = 1;

	return rt;
}

void calc_palindrome()
{
	long i, j;

	palindrome[0] = '0';
	palindrome[len + 1] = 0;	/* string end */
	palindrome[1] = palindrome[len] = orig[0];
	i = 1;
	while (i <= len / 2) {
		palindrome[i + 1] = palindrome[len - i] = orig[i] < orig[len - 1 - i] ?
			orig[i] : orig[len - 1 - i];
		i++;
	}

	if (check_larger(len) == 0) {
		/* nothing */
	}
	else {
		do {
			palindrome[(len + 1) / 2] = palindrome[len + 1 - (len + 1) / 2] =
				palindrome[(len + 1) / 2] + 1;
			if(check_carry(len)) {
				/* 進位後， palindrome 唯一 */
				palindrome[0] = palindrome[len] = '1';
				palindrome[len + 1] = 0;
				for (i = 1; i < len; i++) {
					palindrome[i] = '0';
				}
				break;
			}
		} while (check_larger(len));
	}
}

void prints()
{
	long i;
	if (palindrome[0] == '0')
		i = 1;
	else
		i = 0;
	printf("%s\n", palindrome + i);
}

int main()
{
	int k;
	scanf("%d", &k);
	while (k--) {
		scanf("%s", orig);
		len = strlen(orig);
		calc_palindrome();
		prints();
	}

	return 0;
}

/*
int main()
{
	int t;
	long tmp;
	char c[1000000];
	int i, j, tt;

	scanf("%d", &t);
	while (t) {
		scanf("%s", c[1]);
		if (c[1] == '0' && c[2] == 0) {
			printf("1\n");
			t--;
			continue;
		}
		i = strlen( c+1 );
		c[i] = c[1];
		for (j = i - 1; j > i / 2; j--) {
			if (c[j] < c[i - j + 1])
				c[i - j + 1] = c[j];
			else
				c[j] = c[i - j + 1];

		}
		j = i / 2 + 1;
		c[j] ++;
		if (c[j] > '9') {
			c[j] = c[i - j + 1] = '0';
			tt = j;
			do {
				tt++;
				c[tt]++;
				c[i - tt + 1] = c[tt];
				if (c[tt] > '9') {
					c[tt + 1]++;
					c[i - tt] = c[tt + 1];
					c[tt] = c[i - tt + 1] = '0';
				}
			}while (c[tt + 1] > '9');
		}
		else {
			c[i - j + 1] = c[j];
		}

		puts(c);

		t--;
	}
	return 0;
}
*/
