#include<stdio.h>
#define size 10
int n;
int largest(int a[n]){
    int large=-1;
    for(int i=0;i<n;i++){
        if(a[i]>large){
            large=a[i];
        }
    }
    return large;
}
void radixsort(int a[n]){
    int a1[size][size],bcount[n];
    int ks=0,divisor=1;
    int large=largest(a);
    while(large>0){
        large/=10;
        ks++;
    }
    for(int pass=0;pass<ks;pass++){
        for(int i=0;i<n;i++){
            bcount[i]=0;
        }
        for(int i=0;i<n;i++){
            int rem=(a[i]/divisor)%size;
            a1[rem][bcount[rem]]=a[i];
            bcount[rem]+=1;
        }
        int i=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<bcount[j];k++){
                    a[i++]=a1[j][k];
            }
        }divisor*=10;
    }   
}
void main(){
    printf("Enter the number of elements to be compared\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements to be compared :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }printf("Entered elements before sorting : ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }printf("\n");
    radixsort(a);
    printf("Entered elements after sorting : ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }printf("\n");
}