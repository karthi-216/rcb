#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100],top=-1;
void push(char n){
    stack[++top]=n;
}
char pop(){
    return stack[top--];
}
int main(){
    char s[100],revs[100],i;
    printf("Enter the String :");
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        push(s[i]);
    }
    for(i=0;i<strlen(s);i++){
        revs[i]=pop();
    }
    revs[i]='\0';
    if((strcmp(s,revs)) == 0){
        printf("%s is a palindrome",s);
    }  
    else{
        printf("%s is not a palindrome",s);
    }  
    return 0;
}