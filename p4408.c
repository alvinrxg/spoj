/* http://www.spoj.pl/problems/FENCE1/ */

#include <stdio.h>
#define PI 3.141593

int main()
{
	int l;
	float area;

	while (scanf("%d", &l) != EOF) {
		if (l == 0)
			break;

		area = (float)l * l / 2 / PI;

		printf("%.2f\n", area);
	}
	return 0;
}
