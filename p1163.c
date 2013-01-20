/* http://www.spoj.pl/problems/JAVAC/ */

#include <stdio.h>
#include <string.h>

int main()
{
	char c[102];
	char new[202];
	int len;
	int i, j;
	int type;

	while (scanf("%s", c) != EOF) {
		len = strlen(c);

		i = 0;
		j = 0;
		type = 0;
		while (i < len) {
			if (c[i] == '_' && type == 0 && i) {
				type = 1;
			}
			else if (c[i] >= 'A' && c[i] <= 'Z' && type == 0 && i) {
				type = 2;
			}
			if ((c[i] == '_' && type != 1)
					|| (c[i] == '_' && c[i] == '_')
					|| (c[i] >= 'A' && c[i] <= 'Z' && type != 2)) {
				type = -1;
				break;
			}

			if (c[i] == '_' && c[i + 1] >= 'a' && c[i + 1] <= 'z'
					&& type == 1) {
				new[j] = c[i + 1] - 32;
				i++;
			}
			else if (c[i] == '_' && (c[i + 1] == '_' || c[i + 1] == 0)
					&& type == 1) {
				j--;
				// nothing
			}
			else if (c[i] >= 'A' && c[i] <= 'Z' && type == 2) {
				new[j] = '_';
				new[j + 1] = c[i] + 32;
				j++;
			}
			else {
				new[j] = c[i];
			}

			i++;
			j++;
		}
		new[j] = 0;
		if (type == -1) {
			printf("Error!\n");
		}
		else {
			puts(new);
		}
	}
	return 0;
}
