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
    else if(start->data==key){
        node *ptr=start;
        start=start->next;
        printf("Deleted element is %d",ptr->data);
        free(ptr);
    }
    else{
        node *ptr=start;
        node *temp=ptr;
        while(ptr!=NULL && ptr->data==key){
            temp=ptr;
            ptr=ptr->next;            
        }
        if(ptr->data==key){
            temp->next=ptr->next;
            printf("Deleted element is %d\n",ptr->data);
            free(ptr);
        }
        else{
            printf("Data not found.\n");
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
    printf("2.deleting key node\n");
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
        printf("Enter the data to be deleted :");
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