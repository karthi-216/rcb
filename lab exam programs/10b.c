#include<stdio.h>
int fibo(int n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else return (fibo(n-1)+fibo(n-2));
}
int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    int fi=fibo(n);
    printf("The fibinoci number at %dth pos is %d",n,fi);
    return 0;
}