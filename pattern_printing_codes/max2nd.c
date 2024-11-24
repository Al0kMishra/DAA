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
    for(i=0;i<n;i++){
        if(arr[i]>max){
            max2=max;
            max=arr[i];
        }
        else if(arr[i]>max2){
            max2=arr[i];
        }
    }
    printf("2nd Max Number In Array is = %d",max2);
}  
