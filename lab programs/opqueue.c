 #include<stdio.h>
 #include<stdlib.h>
 #define MAX 3

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return ;
    }
    else
    {
        if(front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = item;
        printf("%d Inserted\n",item);
    }
}
void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty! Nothing to delete.\n");
        return;
    }
    printf("%d Deleted\n", queue[front]);
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    if(front==-1)
        printf("Queue is Empty:\n");
    else
    {
        printf("Queue elemets are:");
        for(int i=front;i<=rear;i++)
            printf("\n%d",queue[i]);
    }
}

int main()
 {
    int ch,ele;

    while(1)
    {
        printf("\n---OPTIONS---\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.exit\n");
        printf("enter choice:");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("enter element to be Inserted:");
            scanf("%d",&ele);
            insert(ele);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default : printf("INVALID CHOICE\n");
        }
    }
    return 0;
 }

