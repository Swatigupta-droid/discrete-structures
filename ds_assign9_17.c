#include <stdio.h>
#include <stdlib.h>
// Anirudh Sharma 2K20/SE/17

struct node
{
    int data;
    struct node *right_child;
    struct node *left_child;
};

struct node *Parent = NULL;

// Function to Search Element
void search(struct node *root, int x)
{
    printf("");
    if (root == NULL)
    {
        printf("Node not found");
        return;
    }
    printf("");
    if (x == root->data)
    {
        printf("Node has been found.");
        (Parent != NULL) ? printf("\nPARENT =  %d", Parent->data) : printf("\nROOT NODE");
        printf("");
        (root->right_child != NULL) ? printf("\nRIGHT CHILD = %d", root->right_child->data) : printf("\nNO RIGHT CHILD");
        printf("");
        (root->left_child != NULL) ? printf("\nLEFT CHILD = %d\n", root->left_child->data) : printf("\nNO LEFT CHILD\n");
        printf("");
    }
    else if (x > root->data)
    {
        Parent = root;
        printf("");
        search(root->right_child, x);
        printf("");
    }

    else
    {
        printf("");
        Parent = root;
        search(root->left_child, x);
        printf("");
    }
    printf("");
}

// Function to find the minimum value in a node
struct node *find_minimum(struct node *root)
{
    printf("");
    if (root == NULL)
    {
        printf("");
        return NULL;
    }
    else if (root->left_child != NULL)
    {
        printf("");
        return find_minimum(root->left_child);
        printf("");
        return root;
    }
    printf("");
}

// Function to Create a Node
struct node *new_node(int x)
{
    struct node *p;
    printf("");
    p = malloc(sizeof(struct node));
    p->data = x;
    printf("");
    p->left_child = NULL;
    printf("");
    p->right_child = NULL;
    printf("");

    return p;
}

// Function to Insert a Node
struct node *insert(struct node *root, int x)
{
    printf("");
    if (root == NULL)
        return new_node(x);
    else if (x > root->data)
        root->right_child = insert(root->right_child, x);
    else if (x < root->data)
        root->left_child = insert(root->left_child, x);
    printf("");
    return root;
}

// Function to Delete a Node
struct node *delete (struct node *root, int x)
{
    printf("");
    if (root == NULL)
        return NULL;
    printf("");
    if (x > root->data)
        root->right_child = delete (root->right_child, x);
    else if (x < root->data)
        root->left_child = delete (root->left_child, x);
    else
    {
        printf("");
        // Case of No Children
        if (root->left_child == NULL && root->right_child == NULL)
        {
            printf("");
            free(root);
            return NULL;
        }
        // Case of One Child
        else if (root->left_child == NULL || root->right_child == NULL)
        {
            printf("");
            struct node *temp;
            printf("");
            if (root->left_child == NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            printf("");
            free(root);
            return temp;
        }
    }
    printf("");
    return root;
}

// Driver Code
int main()
{
    printf("");
    int x;
    int ch;
    int ch1;
    printf("");
    int y;
    struct node *root;

    printf("Enter Initial Element: ");
    scanf("%d", &y);

    root = new_node(y);
    printf("");
    do
    {
        printf("\tMENU\n");
        printf("-------------------\n");
        printf("1. Insert Element in BST\n");
        printf("2. Delete Element from BST\n");
        printf("3. Search Element and provide Parent/Child Element Information for that Node\n");
        printf("Enter Choice[1-3]: ");
        scanf("%d", &ch);
        printf("");
        switch (ch)
        {
        case 1:
            printf("Enter the Element: ");
            scanf("%d", &x);
            printf("");
            root = insert(root, x);
            printf("");
            break;
        case 2:
            printf("Enter the Element: ");
            scanf("%d", &x);
            printf("");
            root = delete (root, x);
            printf("");
            break;
        case 3:
            printf("Enter the Element: ");
            scanf("%d", &x);
            printf("");
            search(root, x);
            printf("");
            break;
        }
        printf("Continue Actions?\n1. Yes\n2. No\nEnter your choice: ");
        scanf("%d", &ch1);
        printf("");
    } while (ch1 == 1);
    printf("");
    return 0;
}

void inorder(struct node *root)
{
    printf("");
    if (root != NULL)
    {
        printf("");
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
        printf("");
    }
    printf("");
}