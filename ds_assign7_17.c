#include <stdio.h>
#include <stdlib.h>
// Anirudh Sharma 2K20/SE/17

struct node
{
    int num;
    struct node *next;
};

struct node *start = NULL, *ptr, *ne;

int c = 0;
void push();
void pop();
void display();
void peek();

// Driver Code
int main()
{
    int n;
    printf("Enter the size of the linked stack: ");
    scanf("%d", &n);
    int ch1;
    int ch;

    do
    {
        printf("\tMENU\n");
        printf("-------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek \n");
        printf("Enter your Choice[1-4]: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
            {
                if (c < n)
                    push();
                else
                    printf("Stack Overflow\n");

                break;
            }
            case 2:
            {
                if (c > 0)
                    pop();
                else
                    printf("Stack Underflow\n");

                break;
            }
            case 3:
            {
                if (c > 0)
                    display();
                else
                    printf("Stack Underflow\n");

                break;
            }
            case 4:
            {
                if (c > 0)
                    peek();
                else
                    printf("Stack Underflow\n");
                break;
            }

            default:
            {
                printf("ERROR!Wrong Choice!\n");
                break;
            }
        }
        printf("Continue Actions?\n1. Yes\n2. No\nEnter your choice: ");
        scanf("%d", &ch1);
    } 
    while (ch1 == 1);
}
// Function for Displaying(Entire Stack)
void display()
{
    int c = 1;
    ptr = start;
    printf("The stack: \n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->num);
        ptr = ptr->next;
        c = c + 10;
    }
    printf("\n");
}
// Function for Peek(Viewing Top-most element)
void peek()
{
    ptr = start;
    printf("The Top-Most element viewed by peek: ");
    printf("%d\n", ptr->num);
}
// Function for Push
void push()
{
    c++;
    if (start == NULL)
    {
        ne = (struct node *)malloc(sizeof(struct node));

        printf("Enter the number: ");
        scanf("%d", &ne->num);
        start = ne;
        ne->next = NULL;
    }
    else
    {
        ne = (struct node *)malloc(sizeof(struct node));

        printf("Enter the number: ");
        scanf("%d", &ne->num);
        ne->next = start;
        start = ne;
    }
}
// Function for Pop
void pop()
{
    c--;
    ptr = start;
    start = ptr->next;
    free(ptr);
    printf("Node Deleted from the beginning\n");
}