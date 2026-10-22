
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int value) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node *minNode(Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void freeTree(Node *root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    Node *root = NULL;
    int choice, value;

    do {
        printf("\n1.Insert  2.Delete  3.Inorder  0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Value: ");
                if (scanf("%d", &value) != 1) {
                    freeTree(root);
                    return 1;
                }
                root = insert(root, value);
                break;

            case 2:
                printf("Value to delete: ");
                if (scanf("%d", &value) != 1) {
                    freeTree(root);
                    return 1;
                }
                root = deleteNode(root, value);
                break;

            case 3:
                inorder(root);
                printf("\n");
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    freeTree(root);
    return 0;
}
