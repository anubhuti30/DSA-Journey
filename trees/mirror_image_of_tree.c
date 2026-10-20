
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

/* Professor's Mirror Image Function */
void mirrorimage(treenode **tree)
{
    treenode *temp;

    if (*tree != NULL)
    {
        mirrorimage(&((*tree)->left));
        mirrorimage(&((*tree)->right));

        temp = (*tree)->left;
        (*tree)->left = (*tree)->right;
        (*tree)->right = temp;
    }
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
        printf("5. Mirror Image\n");
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
                {
                    mirrorimage(&root);
                    printf("Mirror image created successfully.\n");
                    printf("Preorder of mirror tree: ");
                    preorder(root);
                }
                else
                    printf("Create the tree first.");
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
