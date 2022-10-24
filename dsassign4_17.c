#include <stdio.h>
#include <stdlib.h>
// Anirudh Sharma 2K20/SE/17

struct Node
{
    int num;
    struct Node *next;
} * front, *newptr, *rear;
struct Node *new_node()
{
    newptr = (struct Node *)malloc(sizeof(struct Node));
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    newptr->num = val;
    newptr->next = NULL;
    return newptr;
};
void Insert();
void Display();
void Del_Node();

// Driver Code
int main()
{
    front = rear = NULL;
    int ch;
    char c;
    do
    {
        printf("Menu\n");
        printf("-------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("Enter your Choice :- ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            {
                Insert();
                break;
            }
            case 2:
            {
                Del_Node();
                break;
            }
            case 3:
            {
                Display();
                break;
            }
            default:
            {
                printf("ERROR\n");
                break;
            }
        }
        printf("Do you want to continue(Y/N)\n");
        scanf(" %c", &c);
    } while (c == 'Y' || c == 'y');
}

void Insert()
{
    struct Node *np = new_node();

    if (rear == NULL)
    {
        front = rear = np;
    }
    else
    {
        rear->next = np;
        rear = np;
    }
}

void Del_Node()
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        struct Node *np = front;
        int n = front->num;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
        free(np);
        printf("Deleted element %d\n", n);
    }
}

void Display()
{
    struct Node *np = front;
    if (!np)
    {
        printf("Empty queue\n");
        return;
    }
    printf("Data\n");
    while (np != NULL)
    {
        printf("%d ", np->num);
        np = np->next;
    }
    printf("\n");
}