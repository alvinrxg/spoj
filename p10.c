#include <stdio.h>

char str[251];
int len;

void prints()
{
	int i;
	for(i = 0; i < len; i++) {
		if(str[i])
			printf("%c", str[i]);
	}
	printf("\n");
}

void del(char s[])
{
	int i, f;
	f = 0;
	for(i = 0; ;i++) {
		if(s[i] == '(' && f == 0) {
			s[i] = 0;
			f++;
		}
		else if(s[i] == '(' && f > 0)
			f++;
		else if(s[i] == ')' && f == 0) {
			s[i] = 0;
			break;
		}
		else if(s[i] == ')' && f > 0)
			f--;
	}
}

char func(char s[])
{
	int i;
	char op, re;

	op = 0;
	re = 0;
	for(i = 0; ; i++) {
		if(s[i] >= '*' && s[i] <= '/')
			op = s[i];
		else if(s[i] == '(') {
			re = func(s[i + 1]);
			break;
		}
		else if(s[i] == ')')
			break;
	}
	if(s[i] == ')')
		return op;
	else if(op == '+' && re)
		del(s);
	else if(op == '-' && re && re != '-')
		del(s);
	else if(op == '*' && re && (re == '*' || re == '/'))
		del(s);

	return 0;
}

int main()
{
	int n;
	int i;

	scanf("%d\n", &n);
	for(i = 0; i < n; i++) {
		gets(str);
		len = sizeof(str);
		func(str);
		prints();
	}
	return 0;
}
