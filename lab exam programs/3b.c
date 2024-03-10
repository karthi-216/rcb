#include<stdio.h>
#include<stdlib.h>
typedef struct s{
    char name[50];
    int usn;
    int marks[3];
    float average;
}Student;
int main(){
    int n;
    printf("Enter the number of students details to be stored : ");
    scanf("%d",&n);
    Student s[n];
    printf("Enter the Student Details\n");
    for(int i=0;i<n;i++){
        printf("Enter the details of Student %d\n",(i+1));
        printf("NAME :");
        scanf("%s",s[i].name);
        printf("usn : ");
        scanf("%d",&s[i].usn);
        printf("Enter the scores in 3 subjects :\n");
        int max=0;
        for(int j=0;j<3;j++){
            scanf("%d",&s[i].marks[j]);
            max+=s[i].marks[j];
        }
        s[i].average=(max/3);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[i].average<s[j].average){
                Student temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    printf("Students Details\n");
    for(int i=0;i<n;i++){
        printf("Details of student %d\n",i+1);
        printf("Name : %s\nusn : %d\n",s[i].name,s[i].usn);
        printf("Marks in 3 Subjects : ");
        for(int j=0;j<3;j++){
            printf("%d ",s[i].marks[j]);
        }printf("\n");
        printf("Average : %f\n",s[i].average);        
    }
    return 0;
}