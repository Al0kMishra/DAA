#include<stdio.h>
int main(){
    int n, a, i;
    printf("Enter length of array: ");
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&a);
        arr[i]=a;
    }
    int hi, low, mid;
    hi = n-1;
    low = 0;
    mid = (hi+low)/2;
    printf("Enter the number to search: ");
    scanf("%d", &a);
    while(low<=hi){
        if(arr[mid] == a){
            printf("Yes");
            break;
        }
        if(a>arr[mid])
            low = mid+1;
        else if(a<arr[mid])
            hi = mid-1;    
        mid = (hi+low)/2;    
    }
    if(arr[mid]!=a)
        printf("NO");
}

