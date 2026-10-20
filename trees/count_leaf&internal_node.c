
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *getnode()
{
    return (treenode *)malloc(sizeof(treenode));
}

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
        insert(&((*tree)->left), x);
    else
        insert(&((*tree)->right), x);
}

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

void preorder(treenode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(treenode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void postorder(treenode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

/* Count Leaf Nodes */
int countLeaf(treenode *tree)
{
    if (tree == NULL)
        return 0;

    if (tree->left == NULL && tree->right == NULL)
        return 1;

    return countLeaf(tree->left) +
           countLeaf(tree->right);
}

/* Count Internal Nodes */
int countInternal(treenode *tree)
{
    if (tree == NULL)
        return 0;

    if (tree->left == NULL && tree->right == NULL)
        return 0;

    return 1 + countInternal(tree->left) +
               countInternal(tree->right);
}

int main()
{
    treenode *root = NULL;
    int choice, n;

    do
    {
        printf("\n\n----- BINARY TREE MENU -----\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Count Leaf Nodes\n");
        printf("6. Count Internal Nodes\n");
        printf("7. Exit\n");

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
                        printf("Number of nodes must be positive.\n");
                }
                else
                {
                    printf("Tree is already created.\n");
                }
                break;

            case 2:
                if (root != NULL)
                {
                    printf("Preorder: ");
                    preorder(root);
                }
                else
                    printf("Create the tree first.");
                break;

            case 3:
                if (root != NULL)
                {
                    printf("Inorder: ");
                    inorder(root);
                }
                else
                    printf("Create the tree first.");
                break;

            case 4:
                if (root != NULL)
                {
                    printf("Postorder: ");
                    postorder(root);
                }
                else
                    printf("Create the tree first.");
                break;

            case 5:
                if (root != NULL)
                    printf("Leaf Nodes = %d",
                           countLeaf(root));
                else
                    printf("Create the tree first.");
                break;

            case 6:
                if (root != NULL)
                    printf("Internal Nodes = %d",
                           countInternal(root));
                else
                    printf("Create the tree first.");
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
