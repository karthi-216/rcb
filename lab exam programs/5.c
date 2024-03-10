#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node* insertfront(node *start,int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=start;
    start=newnode;
    return start;
}
node* deletekey(node *start,int key){
    if(start==NULL){
    printf("Empty Linked List\n");
    return start;
    }
    else{
        node *ptr=start;
        while(ptr!=NULL && ptr->data!=key){
            ptr=ptr->next;            
        }
        if(ptr== NULL){
            printf("Key not found.\n");
        }
        else{
            printf("Key element found is %d\n",ptr->data);
        }
    }
    return start;
}
void display(node *start){
    if(start==NULL){
        printf("Empty linked list\n");
    }
    node *ptr=start;
    printf("The data elements are : ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }printf("\n");
}
void main(){
    int n,key,choice;
    node *start=NULL;
    while(1){
    printf("Enter the choice according to the operation to be performed\n");
    printf("1.Insertion at front\n");
    printf("2.searching a key node\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice :");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the key to be inserted :");
        scanf("%d",&n);
        start=insertfront(start,n);
        break;
        case 2:
        printf("Enter the data to be searched :");
        scanf("%d",&key);
        start=deletekey(start,key);
        break;
        case 3:
        display(start);
        break;
        case 4:
        exit(0);
    }
    }
}