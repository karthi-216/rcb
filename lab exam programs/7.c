#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node;
node* insertfront(node *start,int n){

    return start;
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
            start=insetfront(start,n);
            break;
            case 2:
            printf("Enter the  value to be Inserted : ");
            scanf("%d",&n);
            printf("Enter the key before which the value should be inserted\n");
            scanf("%d",&key);
            start=insertatkey(start,n,key);
            break;
        }
    }
}