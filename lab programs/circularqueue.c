#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    printf("Item inserted successfully.\n");
}

void dequeue()
{
    int item;

    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }
    item = queue[front];
    printf("Deleted item: %d\n", item);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
        {
            break;
        }
    i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    switch (choice)
        {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
