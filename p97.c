/* http://www.spoj.pl/problems/PARTY/ */
/*	fail	*/

#include <stdio.h>

int main()
{
	int budget, party;
	int fee[100], fun[100];
	float prop[100];
	int i, j;
	int max;
	int fee_sum, fun_sum;

	while (1) {
		scanf("%d %d", &budget, &party);
		if (budget == 0 && party == 0)
			break;
		i = 0;
		while (i < party) {
			scanf("%d %d", &fee[i], &fun[i]);
			prop[i] = (float)fun[i] / fee[i];
			i++;
		}

		max = 0;
		fee_sum = fun_sum = 0;
		for (i = 0; i < party; i++) {
			for (j = 0; j < party; j++) {
				if (prop[j] > prop[max])
					max = j;
			}


			// printf("prop[%d] = %f\tfun[%d] = %d\tfee[%d] = %d\n",
					// max, prop[max], max, fun[max], max, fee[max]);
			if (fee_sum + fee[max] <= budget) {
				fee_sum += fee[max];
				fun_sum += fun[max];
			}
			else
				break;
			prop[max] = 0;
		}
		printf("%d %d\n", fee_sum, fun_sum);
	}
	return 0;
}
