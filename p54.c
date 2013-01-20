#include <stdio.h>
#include <string.h>

char n1[102], n2[102];
char a[102], b[102];

void printall(char s[])
{
	int i;
	for(i = 101; i >= 0; i --)
		if(s[i])
			break;
	if(i >= 0) {
		for(i; i >= 0; i--)
			printf("%d", s[i]);
		printf("\n");
	}
	else {
		printf("0\n");
	}
}

void divide(char s[], int k)
{
	int i;
	for(i = k; i >= 0; i--) {
		/* if k == 0 ....*/
		if(s[i] % 2 && i > 0) {
			s[i]--;
			s[i - 1] += 10;
		}
		s[i] /= 2;
	}
	printall(s);
}

void calc_b()
{
	int i, j, k;
	int l1, l2;
	l1 = strlen(n1);
	l2 = strlen(n2);

	k = 0;
	for(i = l1 - 1, j = l2 - 1; i >= 0 && j >= 0; i--, j--) {
		if(n1[i] < n2[j]) {
			n1[i] += 10;
			n1[i - 1]--;
		}
		b[k] = n1[i] - n2[j];
		k++;
	}
	if(i >= 0) {
		for(i = i; i >= 0; i--) {
			if(n1[i] < '0' && i > 0){
				n1[i] += 10;
				n1[i - 1]--;
			}
			b[k] = n1[i] - '0';
			k++;
		}
	}
	divide(b, k - 1);
}

void calc_a()
{
	int i, j, k;
	int l1, l2, inc;
	l1 = strlen(n1);
	l2 = strlen(n2);

	k = 0;
	inc = 0;
	for(i = l1 - 1, j = l2 - 1; i >= 0 && j >= 0; i--, j--) {
		a[k] = a[k] + n1[i] + n2[j] - '0' * 2;
		a[k + 1] = a[k] / 10;
		a[k] = a[k] % 10;
		k++;
	}
	if(i >= 0) {
		for(i = i; i >= 0; i--) {
			a[k] = a[k] + n1[i] - '0';
			a[k + 1] = a[k] / 10;
			a[k] = a[k] % 10;
			k++;
		}
	}
	/* divide 2 */
	if(a[k])
		divide(a, k);
	else
		divide(a, k - 1);
}
int main()
{
	int i, j;

	while (scanf("%s", n1) != EOF) {
		scanf("%s", n2);
		if (*n1 == '0') {
			puts("0\n0");
			continue;
		} else if (*n2 == '0') {
			puts(n1);
			puts("0");
			continue;
		}
		for(j = 0; j < 102; j++){
			a[j] = b[j] = 0;
		}
		calc_a();
		calc_b();
	}
	return 0;
}
