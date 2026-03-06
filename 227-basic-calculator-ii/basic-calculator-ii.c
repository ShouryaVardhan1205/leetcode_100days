#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calculate(char* s) {
    int stack[300000];
    int top = -1;

    long num = 0;
    char op = '+';

    for (int i = 0; i <= strlen(s); i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (op == '+')
                stack[++top] = num;

            else if (op == '-')
                stack[++top] = -num;

            else if (op == '*')
                stack[top] = stack[top] * num;

            else if (op == '/')
                stack[top] = stack[top] / num;

            op = s[i];
            num = 0;
        }
    }

    int result = 0;

    while (top >= 0)
        result += stack[top--];

    return result;
}