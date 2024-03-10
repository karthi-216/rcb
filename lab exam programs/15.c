#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *insertnode(struct node *root, int val) {
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

void preorderTraversal(struct node *root) {
    if(root != NULL) {
        printf("%d\t", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }    
}

void inorderTraversal(struct node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }   
}

void postorderTraversal(struct node *root) {
    if(root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t", root->data);
    }  
}

int main() {
    int option, val;
    while(1) {
        printf("\n1. Insert Element");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your option:\n ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\nEnter Value: ");
                scanf("%d", &val);
                root = insertnode(root, val);
                break;
            case 2:
                printf("\nPre-order Traversal: \n");
                preorderTraversal(root);
                break;
            case 3:
                printf("\nIn-order Traversal: \n");
                inorderTraversal(root);
                break;
            case 4:
                printf("\nPost-order Traversal: \n");
                postorderTraversal(root);
                break;
            case 5:
                exit(0);
        }  
    }      
    return 0;     
}
