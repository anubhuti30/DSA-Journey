#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
}treenode;

treenode *getnode()
{
    return (treenode*)malloc(sizeof(treenode));
}

treenode *createtree(treenode *root,int n)
{
    treenode *p,*q,*nnode;
    int x,i;
    printf("Enter the number of elements: ",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&x);
    nnode=getnode();
    if(nnode==NULL)
    {
        printf("Memory allocation failed");
        return root;
    }
    nnode->info=x;
    nnode->left=NULL;
    nnode->right=NULL;
    if(root==NULL)
    {
        root=nnode;
    }
    else
    {
        p=root;
        q=NULL;
        while(p!=NULL)
        {
            q=p;
            if(p->info>x)
            p=p->left;
            else
            p=p->right;
        }
        if(x<q->info)
        q->left=nnode;
        else
        q->right=nnode;
    }
    }return root;
}
void insertnode(treenode **tree,int x)
{
    if(*tree==NULL)
    {
        (*tree)=getnode();
       if(*tree==NULL)
       {
           printf("Memory aloocation failed\n");
           return;
       }
        (*tree)->info=x;
        (*tree)->left=NULL;
        (*tree)->right=NULL;
    }
    else if(x<(*tree)->info)
    insertnode(&(*tree)->left,x);
    else
    insertnode(&(*tree)->right,x);
}
void preorder(treenode *root)
{
    if(root!=NULL)
    {
        printf("%d",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(treenode *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->info);
        inorder(root->right);
    }
}
void postorder(treenode *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->info);
    }
}
int main()
{
    treenode*root=NULL;
    int choice,n;
    do
    {
        printf("\n1.Create 2.Preorder 3.Inorder 4.Postorder 5.Exit");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
             case 1:
                if (root == NULL)
                {
                    printf("Enter number of nodes: ");
                    scanf("%d", &n);

                    if (n > 0)
                        root = createtree(root, n);
                    else
                        printf("Number of nodes must be positive.\n");
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
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }while(choice!=5);
    return 0;
}