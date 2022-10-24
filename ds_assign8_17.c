#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Anirudh Sharma 2K20/SE/17

struct TreeNode
{
    char info;
    struct TreeNode *left, *right;
};

int isDigit(char ch)
{
    if (ch > 47 && ch < 57)
        return 1;
    return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        return 1;
    return 0;
}

struct TreeNode *Create_Node(char info)
{
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (temp == NULL)
    {
        printf("Out of space!\n");
        return (temp);
    }

    temp->left = NULL;
    temp->right = NULL;
    temp->info = info;
    return temp;
};

struct TreeNode *constructTree(struct TreeNode *tree, char postfix[])
{
    int i = 0;
    struct TreeNode *st[100];
    int top = -1;
    struct TreeNode *temp_tree1;
    struct TreeNode *temp_tree2;
    while (postfix[i] != '\0')
    {
        if (!(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '^'))
        {
            tree = Create_Node(postfix[i]);
            top = top + 1;
            st[top] = tree;
        }
        else
        {
            tree = Create_Node(postfix[i]);
            temp_tree1 = st[top];
            top = top - 1;

            temp_tree2 = st[top];
            top = top - 1;

            tree->right = temp_tree1;
            tree->left = temp_tree2;

            top = top + 1;
            st[top] = tree;
        }
        i++;
    }
    return tree;
}

// Function to Show Node
void show_node(struct TreeNode *T)
{
    printf("%c ", T->info);
}

// Function for PreOrder Traversal
void preorder(struct TreeNode *T)
{
    if (T != NULL)
    {
        show_node(T);
        preorder(T->left);
        preorder(T->right);
    }
}

// Function for PostOrder Traversal
void postorder(struct TreeNode *T)
{
    if (T != NULL)
    {
        postorder(T->left);
        postorder(T->right);
        show_node(T);
    }
}

// Display Function
void display(struct TreeNode *tree, char postfix[])
{
    printf("\n\t*************TRAVERSALS*************\n");

    printf("\nPreOrder Traverse  (Parent, Left, Right) Postfix Expression :  ");
    preorder(tree);

    printf("\nPostOrder Traverse (Left, Right, Parent) Prefix Expression  : ");
    postorder(tree);
}

// Function to sort Priority
int getPriority(char ch)
{
    switch (ch)
    {
    case '^':
        return 4;
    case '%':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

// Function to convert Infix Expression to Postfix Expression
void Convert_In_To_Post(char infix[], char postfix[])
{
    unsigned int counter1 = 0;
    char st[100];
    int top = -1;
    int postCount = 0;
    char element;
    while (counter1 < strlen(infix))
    {
        element = infix[counter1];
        if (element == '(')
        {
            top = top + 1;
            st[top] = element;
            counter1++;
            continue;
        }

        if (element == ')')
        {
            while (top != -1 && st[top] != '(')
            {
                postfix[postCount++] = st[top];
                top = top - 1;
                ;
            }
            if (top != -1)
            {
                top = top - 1;
            }
            counter1++;
            continue;
        }

        if (getPriority(element) == 0)
        {
            postfix[postCount++] = element;
        }

        else
        {
            if (top == -1)
            {
                top = top + 1;
                st[top] = element;
            }

            else
            {
                while (top != -1 && st[top] != '(' &&
                       getPriority(element) <= getPriority(st[top]))
                {
                    postfix[postCount++] = st[top];
                    top = top - 1;
                }
                top = top + 1;
                st[top] = element;
            }
        }
        counter1++;
    }

    while (top != -1)
    {
        postfix[postCount++] = st[top];
        top = top - 1;
    }
    postfix[postCount] = '\0';
}

// Driver Code
int main()
{
    printf("\n Enter Expression: ");
    char infix[100];
    gets(infix);

    char *postfix = (char *)malloc(sizeof(char) * strlen(infix));

    Convert_In_To_Post(infix, postfix);

    struct TreeNode *tree1 = NULL;
    tree1 = constructTree(tree1, postfix);
    display(tree1, postfix);
    printf("\n");

    return 0;
}