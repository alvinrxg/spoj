#include <stdio.h>

int m[101][160];

void prints(int d)
{
	int i;
	for(i = 159; i >= 0; i--)
	{
		if(m[d][i])
			break;
	}
	for(i = i; i >= 0; i--)
		printf("%d", m[d][i]);
	printf("\n");
}
void multi(int d)
{
	int i, j;
	int inc;
	inc = 0;
	for(j = 159; j >= 0; j--)
		if(m[d - 1][j])
			break;
	for(i = 0; i <= j; i++) {
		m[d][i] = d * m[d - 1][i] + inc;
		inc = m[d][i] / 10;
		m[d][i] %= 10;
	}
	for(i = i; i < 160; i++)
		if(inc) {
			m[d][i] += inc;
			inc = m[d][i] / 10;
			m[d][i] %= 10;
		}
		else
			break;


}

void calc()
{
	int i;

	m[0][0] = 1;
	for(i = 1; i <= 100; i++) {
		multi(i);
	}
}

int main()
{
	int n, d;
	int i, j;

	for(i = 0; i < 100; i++)
		for(j = 0; j < 160; j++) {
			m[i][j] = 0;
		}
	calc();

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d", &d);
		prints(d);
	}
	return 0;
}


