// http://www.spoj.com/problems/EGYPIZZA/
#include <stdio.h>

int main()
{
	int pizza14 = 0;
	int pizza12 = 0;
	int pizza34 = 0;
	char tmp[4];

	int sum = 1;
	int n;
	int i = 0;
	scanf("%d", &n);
	while (i < n) {
		scanf("%s", tmp);
		if (tmp[2] == '2') {
			pizza12++;
		}
		else if (tmp[0] == '1') {
			pizza14++;
		}
		else if (tmp[0] == '3') {
			pizza34++;
		}
		i++;
	}

	sum += pizza34;
	pizza14 -= pizza34;

	sum += pizza12 / 2;
	if (pizza12 % 2) {
		sum++;
		pizza14 -= 2;
	}


	if (pizza14 > 0) {
		sum += pizza14 / 4;
		if (pizza14 % 4) {
			sum++;
		}
	}

	printf("%d\n", sum);

	return 0;
}
