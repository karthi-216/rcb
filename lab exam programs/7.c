#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node;
node* insertfront(node *start,int n){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->left=NULL;
    newnode->right=start;
    if(start!=NULL){
        start->left=newnode;
    }
    start=newnode;
    return start;
}
node* insertleft(node *start,int n,int key){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->left=NULL;
    newnode->right=NULL;
    if(start==NULL){
        printf("Empty linked list\n");
        return start;
    }
    else if(start->data == key){
        newnode->right=start;
        start->left=newnode;
        start=newnode;
    }
    else{
        node *ptr=start;
        while(ptr!=NULL && ptr->data!=key){
            ptr=ptr->right;
        }
        if(ptr==NULL){
            printf("Key not found\n");
        }
        else{
            newnode->right=ptr;
            newnode->left=ptr->left;
            (ptr->left)->right=newnode;
            ptr->left=newnode;
        }
    }
    return start;
}
void display(node *start){
    if(start==NULL){
        printf("Empty linked list\n");
        return;
    }
    node *ptr=start;
    printf("The data elements are : ");
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->right;
    }printf("\n");
}
void main(){
    int n,key,choice;
    node *start=NULL;
    while(1)
    {
        printf("Enter choice according to the operation to be performed\n");
        printf("1.Insertion at front\n");
        printf("2.Insertion at left of given key\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element to be Inserted : ");
            scanf("%d",&n);
            start=insertfront(start,n);
            break;
            case 2:
            printf("Enter the  value to be Inserted : ");
            scanf("%d",&n);
            printf("Enter the key before which the value should be inserted\n");
            scanf("%d",&key);
            start=insertleft(start,n,key);
            break;
            case 3:
            display(start);
            break;
            case 4:
            exit(0);
        }
    }
}