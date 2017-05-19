#include <stdio.h>

#include "stack.h"

static int getline(char s[], int limit)
{
	int c, i;
	i = 0;

	while ((c = getchar()) != EOF && i < limit - 1 && c != '\n') {
		s[i++] = c;
	}

	s[i] = '\0';
	return c == EOF ? EOF : i;
}

static int is_matched(char left, char right)
{
	if (left == '{' && right == '}')
		return 1;
	if (left == '[' && right == ']')
		return 1;
	if (left == '(' && right == ')')
		return 1;
	return 0;
}

static int is_brackets_balanced(const char *exp)
{
	int c;
	stack *s;
	init(&s);

	while (c = *exp++) {
		//左括号，压栈
		if (c == '{' || c == '[' || c == '(')
			push(s, c);
		//右括号
		else if (c == '}' || c == ']' || c == ')') {
			if (is_empty(s)) //检测此时栈是否为空，若为空，报错
				return 0;
			if (!is_matched(pop(s), c))//弹出栈顶元素，若不匹配，报错
				return 0;
		}

	}
//如果扫描到字符串尾，栈非空，报错
	if (!is_empty(s))
		return 0;

	return 1;

}

int main(void)
{
	char s[100];

	while (getline(s, 100) >= 0) {
		if (is_brackets_balanced(s))
			printf("%s is balanced\n", s);
		else
			printf("%s is not balanced\n", s);
	}
	return 0;
}
