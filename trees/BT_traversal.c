
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

treenode *createTree(treenode *root, int n)
{
    treenode *p, *q, *mnode;
    int x, i;

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);

        mnode = getnode();

        if (mnode == NULL)
        {
            printf("Memory allocation failed.\n");
            return root;
        }

        mnode->info = x;
        mnode->left = NULL;
        mnode->right = NULL;

        if (root == NULL)
        {
            root = mnode;
        }
        else
        {
            p = root;
            q = NULL;

            while (p != NULL)
            {
                q = p;

                if (p->info > x)
                    p = p->left;
                else
                    p = p->right;
            }

            if (x < q->info)
                q->left = mnode;
            else
                q->right = mnode;
        }
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

void inorder(treenode *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->info);
        inorder(tree->right);
    }
}

void postorder(treenode *tree)
{
    if (tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->info);
    }
}

int main()
{
    treenode *root = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of nodes must be positive.\n");
        return 0;
    }

    root = createTree(root, n);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}
