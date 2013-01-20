/* http://www.spoj.pl/problems/ARITH2/ */

#include <stdio.h>

int main()
{
	int t;
	char op;
	long long int num;
	long long int result;
	int k;

	scanf("%d", &t);
	k = 0;
	while (k++ < t) {
		scanf("%lld", &result);
		while (scanf("%c", &op) != EOF) {
			while (op == ' ') {
				scanf("%c", &op);
			}
			if (op == '=')
				break;
			scanf("%lld", &num);
			if (op == '+')
				result += num;
			else if (op == '-')
				result -= num;
			else if (op == '*')
				result *= num;
			else if (op == '/')
				result /= num;
		}
		printf("%lld\n", result);
	}
	return 0;
}
