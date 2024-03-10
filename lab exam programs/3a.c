#include<stdio.h>
#include<stdlib.h>
typedef struct TIME{
    int hour;
    int minute;
    int second;
    struct TIME *next;
}TIME;
void Display(TIME *t1){
    TIME *ptr=t1;
    int i=1;
    while(ptr!=NULL){
        printf("TIme stored in %dth variable : ",i++);
        printf("%d : %d : %d (hours:minutes:seconds)\n",t1->hour,t1->minute,t1->second);
        ptr=ptr->next;
    }
}
TIME* read(TIME *t1){
    printf("HOUR : ");
    scanf("%d",&t1->hour);
    printf("MINUTES : ");
    scanf("%d",&t1->minute);
    printf("SECONDS : ");
    scanf("%d",&t1->second);
    return t1;
}
int main(){
    TIME *t1=(TIME*)malloc(sizeof(TIME));
    TIME *t2=(TIME*)malloc(sizeof(TIME));
    printf("Enter any time in h:m:s format for first variable\n");
    t1=read(t1);
    t1->next=t2;
    printf("Enter any time in h:m:s format for second variable\n");
    t2=read(t2);
    Display(t1);
    free(t1);
    free(t2);
    return 0;
}