#include<stdio.h>
int main(){
    int n;
    printf("Enter length of array: ");
    scanf("%d",&n);
    int arr[n];
    int i,a;
    for(i = 0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&a);
        arr[i]=a;
    }
    printf("Enter Number To Search: ");
    scanf("%d",&a);
    for(i=0;i<n;i++){
        if(arr[i]==a){
            printf("Yes at index = %d",i);
            break;
        }    
    }
    if(i>=n){
        printf("NO");
    }
}