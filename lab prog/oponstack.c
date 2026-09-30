#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int x;
void push(int x);
void pop();
void display();

int stack[MAX];
int top = -1;

int main()
{
    int ch;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PRINT\n");
        printf("4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("INVALID INPUT\n");
        }
    }
}

void push(int x)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = x;
    printf("Element pushed\n");
}

void pop()
{
    if (top <= -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    x = stack[top];
    top = top - 1;
    printf("Element popped: %d\n", x);
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}