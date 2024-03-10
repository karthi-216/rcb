#include<stdio.h> 
#include<stdlib.h>

#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue(int num) {
    if(rear == MAX - 1) {
        printf("\nOVERFLOW");
        return;
    }
    else if(front == -1 && rear == -1) {
        front = rear = 0; 
    }
    else {
        rear++; 
    }
    queue[rear] = num;
}

void dequeue() { 
    if(front == -1 || front > rear) { 
        printf("\nUNDERFLOW"); 
        return;
    } 
    int val = queue[front]; 
    printf("Deleted Item: %d\n", val);
    front++; 
    if(front > rear) {
        front = rear = -1; 
    }
}

void display() { 
    if(front == -1 || front > rear) {
        printf("\nQUEUE EMPTY\n"); 
        return;
    } 
    printf("Queue data:\n");
    for(int i = front; i <= rear; i++) {
        printf("\t%d", queue[i]);
    } 
    printf("\n");
}

int main() { 
    int choice, num; 
    while(1) { 
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        printf("\nEnter the Choice: "); 
        scanf("%d", &choice);
        switch(choice) { 
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &num);
                enqueue(num); 
                break; 
            case 2:
                dequeue(); 
                break;
            case 3:
                display(); 
                break; 
            case 4:
                printf("\nEXIT POINT\n"); 
                exit(0);
            default:
                printf("\nEnter Valid Choice\n");
        }
    }
    return 0; 
}
