#include <stdio.h>
#include <stdlib.h>
// Anirudh Sharma 2K20/SE/17

struct node
{
    int k;
    struct node *l;
    struct node *r;
    int left, right;
};

struct node *root;
int val;

// Function for New Node
void newNode()
{
    printf("");
    val = 65536;
    printf("");
    root = (struct node *)malloc(sizeof(struct node));
    printf("");
    root->r = root->l = root;
    printf("");
    root->left = 1;
    printf("");
    root->right = 0;
    printf("");
    root->k = val;
    printf("");
}

// Function for Inserting
void insert(int key)
{
    struct node *p = root;
    printf("");
    for (;;)
    {
        if (p->k < key)
        {
            printf("");
            if (p->right)
                break;
            printf("");
            p = p->r;
        }
        else if (p->k > key)
        {
            printf("");
            if (p->left)
                break;
            printf("");
            p = p->l;
        }
        else
        {
            printf("");
            return;
        }
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->k = key;
    printf("");
    temp->right = temp->left = 1;
    printf("");
    if (p->k < key)
    {
        printf("");
        temp->r = p->r;
        printf("");
        temp->l = p;
        printf("");
        p->r = temp;
        printf("");
        p->right = 0;
        printf("");
    }
    else
    {
        printf("");
        temp->r = p;
        printf("");
        temp->l = p->l;
        printf("");
        p->l = temp;
        printf("");
        p->left = 0;
        printf("");
    }
}

// Function for Inorder traversal
void inorder()
{
    struct node *temp = root;
    struct node *p;
    printf("");
    for (;;)
    {
        p = temp;
        printf("");
        temp = temp->r;
        printf("");

        if (p->right == 0)
        {
            while (temp->left == 0)
            {
                printf("");
                temp = temp->l;
                printf("");
            }
        }
        if (temp == root)
        {
            printf("");
            break;
        }
        printf("");
        printf("%d ", temp->k);
    }
    printf("");
    printf("\n");
}

// Driver Code
int main()
{
    newNode();
    printf("");
    printf("The Two Way Threaded Binary Tree Appears to be as: \n");
    printf("");

    printf("");
    insert(34);
    printf("");
    insert(8);
    printf("");
    insert(98);
    printf("");
    insert(93);
    printf("");
    insert(57);
    printf("");
    insert(72);
    printf("");
    insert(60);
    printf("");
    insert(52);
    printf("");
    insert(24);
    printf("");
    insert(48);
    printf("");
    insert(7);
    printf("");

    printf("");
    inorder();
    printf("");

    return 0;
}