#include <stdio.h>

int main()
{
	int t;
	long n;
	int k;
	long i;
	long line;
	long nums;

	scanf("%d", &t);
	k = 0;
	while (k++ < t) {
		scanf("%ld", &n);
		line = 1;
		nums = 1;
		while (nums < n) {
			line++;
			nums += line;
		}

		for (i = 0; i < line; i++) {
			if (nums - line + 1 + i == n) {
				break;
			}
		}
		if (line % 2) {
			printf("TERM %d IS %ld/%ld\n", n, line - i, i + 1);
		} else {
			printf("TERM %d IS %ld/%ld\n", n, i + 1, line - i);
		}

	}

	return 0;
}
