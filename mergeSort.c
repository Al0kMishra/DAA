#include<stdio.h>
void merge(int a[], int p, int q, int r){
    int i;
    int n1 =q-p+1;
    int n2 = r-q;
    int arr[n1];
    int brr[n2];
    for(i =0; i<n1; i++){
        arr[i] = a[p+i]; 
    }
    for(i=0;i<n2;i++){
        brr[i] = a[q+1+i];
    }
    int j,k=p;
    i=j=0;
    while(i<n1 && j<n2){
        if(arr[i]<brr[j]){
            a[k++] = arr[i++];
        }
        else{
            a[k++] = brr[j++];
        }
    }
    while(i<n1)
        a[k++]=arr[i++];
    while(j<n2)
        a[k++]=brr[j++];    
}
void mergesort(int a[], int p, int r){
    if(p<r){
        int q;
        q = (p+r)/2;
        mergesort(a, p, q);
        mergesort(a, q+1, r);
        merge(a, p, q, r);
    }
}
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
    mergesort(arr,0,n-1);
    for(i=0; i<n;i++){
        printf("%d ",arr[i]);
    }
}