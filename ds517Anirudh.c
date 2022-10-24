#include <stdio.h>
#include <stdlib.h>
// Anirudh Sharma 2K20/SE/17

// Structure for creating node and pointer 
struct node
{
    int data;
    struct node *next;
} * rear, *front;

// Initialising the pointers in the linked list 
void create()
{
    front = rear = NULL;
}

// Function to insert elements in a circular queue 
int enqueue(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
        return 0;
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front;
    return 1;
}

// Function to delete an element from the circular queue 
int dequeue()
{
    int x;
    if (front == rear) // Queue has only a single node
    {
        x = front->data;
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct node *temp = front;
        x = temp->data;
        front = front->next;
        // Make rear point to the front node
        rear->next = front;
        free(temp);
    }
    return x;
}

// Function to check if the queue is empty 
int empty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
        return 0;
}

// Function to print the elements in the circular queue 
int display()
{
    struct node *temp = front;
    if (!temp)
        return 0;
    printf("\nCIRCULAR QUEUE : ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    return 1;
}

// Main function 
int main()
{
    int num, choice;
    int a;
    int n = 0;
    create();
    while (1)
    {
        printf("\n\nQUEUE OPERATIONS\n\n1.ENQUEUE/PUSH/INSERT\n2.DEQUEUE/POP/DELETE\n3.DISPLAY\n");
        printf("Enter your choice(1/2/3): ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter item : ");
                scanf("%d", &num);
                a = enqueue(num);
                if (!a)
                    printf("Couldn't allocate memory to the node!\n");
                else
                    printf("Successfully inserted new node!\n");
                break;
            case 2:
                a = empty();
                if (!a)
                    printf("\nDequeued element : %d", dequeue());
                else
                    printf("\nQueue is empty!\n");
                break;
            case 3:
                a = display();
                if (!a)
                    printf("Queue is empty!\n");
                break;
            default:
                n = 1;
                break;
        }
        if (n == 1)
            break;
    }
    return 0;
}