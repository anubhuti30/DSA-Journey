
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
} treenode;

/* Create a new node */
treenode *getnode()
{
    return (treenode *)malloc(sizeof(treenode));
}

/* Insert node recursively */
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

/* Create tree */
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

/* Search an element */
int search(treenode *tree, int x)
{
    while (tree != NULL)
    {
        if (tree->info == x)
            return 1;
        else if (x < tree->info)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return 0;
}

/* Count leaf nodes */
int countLeaf(treenode *tree)
{
    if (tree == NULL)
        return 0;

    if (tree->left == NULL && tree->right == NULL)
        return 1;

    return countLeaf(tree->left)
         + countLeaf(tree->right);
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

/* Main menu */
int main()
{
    treenode *root = NULL;
    int choice, n, x;

    do
    {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Element\n");
        printf("6. Count Leaf Nodes\n");
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
                        printf("Invalid number of nodes.\n");
                }
                else
                    printf("Tree already created!\n");
                break;

            case 2:
                if (root != NULL)
                {
                    printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                }
                else
                    printf("Create the tree first!\n");
                break;

            case 3:
                if (root != NULL)
                {
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                }
                else
                    printf("Create the tree first!\n");
                break;

            case 4:
                if (root != NULL)
                {
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                }
                else
                    printf("Create the tree first!\n");
                break;

            case 5:
                if (root != NULL)
                {
                    printf("Enter element to search: ");
                    scanf("%d", &x);

                    if (search(root, x) == 1)
                        printf("Element found.\n");
                    else
                        printf("Element not found.\n");
                }
                else
                    printf("Create the tree first!\n");
                break;

            case 6:
                if (root != NULL)
                    printf("Number of leaf nodes = %d\n",
                           countLeaf(root));
                else
                    printf("Create the tree first!\n");
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
