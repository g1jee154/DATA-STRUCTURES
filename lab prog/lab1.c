#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop(void) {
    if (top < 0) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek(void) {
    return (top < 0) ? '\0' : stack[top];
}

int isEmpty(void) {
    return top == -1;
}

int prec(char op) {
    switch (op) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0; /* '(' */
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(const char *infix, char *postfix) {
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isspace((unsigned char)ch))
            continue; /* ignore spaces */

        if (isalnum((unsigned char)ch)) { /* operand */
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop(); /* discard '(' */
        }
        else if (isOperator(ch)) {
            while (!isEmpty() && prec(peek()) >= prec(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main(void) {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid parenthesized infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
