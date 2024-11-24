#include<stdio.h>
int main(){
    int n;
    int max = 0;
    int max2 = 0;
    printf("Enter length of array: ");
    scanf("%d",&n);
    int arr[n];
    int i,a;
    for(i = 0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&a);
        arr[i]=a;
    }
    for(i=0;i<n/2;i++){
        a=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-i-1]=a;
    }
    for(i=0; i<n;i++){
        printf("%d ",arr[i]);
    }
}