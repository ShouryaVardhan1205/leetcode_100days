#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    char stack[n];
    int top = -1;

    for(int i = 0; i < n; i++) {
        char c = s[i];

        // Push opening brackets
        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else {
            // Stack empty -> invalid
            if(top == -1) return false;

            char t = stack[top--];

            if((c == ')' && t != '(') ||
               (c == '}' && t != '{') ||
               (c == ']' && t != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}