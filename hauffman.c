#include<stdio.h>
#include<stdlib.h>
void merge(int arr[][3],int p,int q,int r) {
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int a[n1][3],b[n2][3];
    for(i=0;i<n1;i++){
        a[i][0]=arr[p+i][0];
        a[i][1]=arr[p+i][1];
        a[i][2]=arr[p+i][2];
    }
    for(j=0;j<n2;j++){
        b[j][0]=arr[q+1+j][0];
        b[j][1]=arr[q+1+j][1];
        b[j][2]=arr[q+1+j][2];
    }
    i=0;
    j=0;
    k=p;
    while(i<n1 && j<n2) {
        if(a[i][0]<=b[j][0]){
            arr[k][0]=a[i][0];
            arr[k][1]=a[i][1];
            arr[k][2]=a[i][2];        
            i++;
        }
        else{
            arr[k][0]=b[j][0];
            arr[k][1]=b[j][1];
            arr[k][2]=b[j][2];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k][0]=a[i][0];
        arr[k][1]=a[i][1];
        arr[k][2]=a[i][2];
        i++;
        k++;
    }
    while(j<n2){
        arr[k][0]=b[j][0];
        arr[k][1]=b[j][1];
        arr[k][2]=b[j][2];
        j++;
        k++;
    }
}
void mergesort(int arr[][3],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
} 
void c(int code[],int arr[][3],int brr[][3],int i){
    int k = 0;
    for(int j = 0;j<9;j++){
        if(brr[i][0] == arr[j][1]){
            code[k+1] = code[k];
            code[k++] = 0;
            printf("%d", code[k-1]);
            c(code,arr,arr,j);
        }
        else if(brr[i][0] == arr[j][2]){
            code[k+1] = code[k];
            code[k++] = 1;
            printf("%d", code[k-1]);
            c(code,arr,arr,j);
        }
    }                 
}

int main(){
    int arr[9][3]={{50,0,0},{25,0,0},{15,0,0},{40,0,0},{75,0,0}};
    int brr[5][3];
    for(int i = 0;i<5;i++){
        brr[i][0] = arr[i][0];
        brr[i][1] = arr[i][1];
        brr[i][2] = arr[i][2];
    }
    int l=4;
    mergesort(arr,0,4);
    for(int i=0;i<9;i+=2){
        int sum = arr[i][0] + arr[i+1][0];
        arr[l+1][0] = sum;
        arr[l+1][1] = arr[i][0];
        arr[l+1][2] = arr[i+1][0];
        mergesort(arr,0,++l); 
    }
    for(int i= 0; i<5;i++){
        int code[9];
        printf("for %d Hauffman code: ", brr[i][0]);
        c(code,arr,brr,i);
        printf("\n");
    }
}