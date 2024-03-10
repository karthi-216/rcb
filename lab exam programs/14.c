#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *root;

NODE *insertnode(NODE *root, int val) {
    struct node *new_node, *ptr, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL)
        root = new_node;
    else {
        ptr = root;
        while(ptr != NULL) {
            temp = ptr;
            if(val < (ptr->data))
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if(val < (temp->data))
            temp->left = new_node;
        else
            temp->right = new_node;
    }
    return root;
}

int totalLeafNodes(NODE *root) {
    if(root == NULL)
        return 0;
    else if((root->left == NULL) && (root->right == NULL)) {
        return 1;
    } else
        return (totalLeafNodes(root->left) + totalLeafNodes(root->right));
}
void printPathsRecur(NODE *root, int path[], int pathlen) {
    int i;
    NODE *temp;
    if(root == NULL) 
        return;
    temp = root;
    path[pathlen] = temp->data;
    pathlen++;
    if (temp->left == NULL && temp->right == NULL) {
        for (i = 0; i < pathlen; i++) 
            printf("%d ", path[i]);
        printf("\n");
    } else {
        printPathsRecur(temp->left, path, pathlen);
        printPathsRecur(temp->right, path, pathlen);
    }
}
void printallpaths(NODE *root) {
    int path[100];
    printPathsRecur(root, path, 0);
}
int main() {
    int option, val;
    NODE *root = NULL;
    while(1) {
        printf("\n1. Insert Element");
        printf("\n2. Count Leaf nodes");
        printf("\n3. Print path");
        printf("\n4. Exit");
        printf("\nEnter your option:\n ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\nEnter Value: ");
                scanf("%d", &val);
                root = insertnode(root, val);
                break;
            case 2:
                printf("\nTotal leaf node = %d\n", totalLeafNodes(root));
                break;
            case 3:
                printallpaths(root);
                break;
            case 4:
                exit(0);
        } 
    }       
    return 0;     
}
