
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
} treenode;

/* Function to create a node */
treenode *getnode()
{
    return (treenode *)malloc(sizeof(treenode));
}

/* Function to insert a node */
void insert(treenode **tree, int x)
{
    if (*tree == NULL)
    {
        *tree = getnode();

        if (*tree == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        (*tree)->info = x;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else if (x < (*tree)->info)
        insert(&(*tree)->left, x);
    else
        insert(&(*tree)->right, x);
}

/* Function to create a tree */
treenode *createTree(treenode *root, int n)
{
    int i, x;

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(&root, x);
    }

    return root;
}

/* Preorder: Root, Left, Right */
void preorder(treenode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Inorder: Left, Root, Right */
void inorder(treenode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

/* Postorder: Left, Right, Root */
void postorder(treenode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

/* Function to calculate height of tree */
int treeheight(treenode *tree)
{
    int lh, rh;

    if (tree == NULL)
        return (-1);

    else if ((tree->left == NULL) &&
             (tree->right == NULL))
        return 0;

    else
    {
        lh = treeheight(tree->left);
        rh = treeheight(tree->right);

        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }
}

/* Main function */
int main()
{
    treenode *root = NULL;
    int choice, n;

    do
    {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Height of Tree\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (root == NULL)
                {
                    printf("Enter number of nodes: ");
                    scanf("%d", &n);

                    if (n > 0)
                        root = createTree(root, n);
                    else
                        printf("Invalid number of nodes.\n");
                }
                else
                    printf("Tree already created!\n");
                break;

            case 2:
                if (root != NULL)
                {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                else
                    printf("Create the tree first!\n");
                break;

            case 3:
                if (root != NULL)
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                else
                    printf("Create the tree first!\n");
                break;

            case 4:
                if (root != NULL)
                {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                else
                    printf("Create the tree first!\n");
                break;

            case 5:
                if (root != NULL)
                    printf("Height of tree = %d\n",
                           treeheight(root));
                else
                    printf("Create the tree first!\n");
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
