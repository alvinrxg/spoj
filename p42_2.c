/*
 * as string
 * FAIL
 */

#include <stdio.h>

/*
int a1i, a2i;

void add(char a1[], char a2[])
{
	int i;
	a1i = a2i = i= 0;
	for(i = 0; i < 62; i++) {
		if(a1[i] == '0')
			a1i++;
		if(a2[i] == '0')
			a2i++;
	}
	while((a1[a1i + i] || a2[a2i + i]) && ((a1i + i) < 64 || (a2i + i) < 64)) {
		a1[a1i + i] += a2[a2i + i] - 48;
		i++;
	}
	i = 0;
	while(a1[a1i + i] && (i + a1i) < 64) {
		if(a1[a1i + i] < '0') {
			a1[a1i + i] += '0';
			continue;
		}
		if(a1[a1i + i] > '9') {
			a1[a1i + i] -= 10;
			a1[a1i + i + 1]++;
		}
		i++;
	}
	i = 63;
	while(i >= 0) {
		if(a1[a1i + i] == '0')
			a1[a1i + i] = 0;
		else if(a1[a1i + i] > '0')
			break;
		i--;
	}
}

void my_print(char a[])
{
	int f;
	int i;
	f = i = 0;
	while(a[a1i + i] && (i + a1i) < 64) {
		if(f == 0 && a[a1i + i] == '0') {

		}
		else {
			f = 1;
			printf("%c", a[a1i + i]);
		}
		i++;
	}
	if(f == 0)
		printf("0");
	printf("\n");
}
*/

int main()
{
	char a1[64], a2[64];
	int n, i;
	int j;

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		for(j = 0; j < 64; j++)
			a1[j] = a2[j] = 0;

		scanf("%s %s", a1, a2);
		add(a1, a2);

		my_print(a1);
	}
	return 0;
}
