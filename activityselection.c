#include<stdio.h>

void merge(int arr[][2], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int a[n1][2], b[n2][2];

    for (int i = 0; i < n1; i++){
        a[i][0] = arr[p + i][0];
        a[i][1] = arr[p + i][1];
    }
    for (int j = 0; j < n2; j++){
        b[j][0] = arr[q + 1 + j][0];
        b[j][1] = arr[q + 1 + j][1];
    }

    int i = 0, j = 0, k = p;
    while(i < n1 && j < n2){
        if (a[i][1] <= b[j][1]){
            arr[k][0] = a[i][0];
            arr[k][1] = a[i][1];
            i++;
        } 
        else{
            arr[k][0] = b[j][0];
            arr[k][1] = b[j][1];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k][0] = a[i][0];
        arr[k][1] = a[i][1];
        i++;
        k++;
    }

    while (j < n2){
        arr[k][0] = b[j][0];
        arr[k][1] = b[j][1];
        j++;
        k++;
    }
}

void mergeSort(int arr[][2], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
int main(){
    int n,a;
    printf("Enter the number of activities: ");
    scanf("%d",&n);
    int arr[n][2] ;
    for(int i=0; i<n;i++){
        printf("Enter a%d Start time: ",i+1);
        scanf("%d",&a);
        arr[i][0]=a;
        printf("Enter a%d End time: ",i+1);
        scanf("%d",&a);
        arr[i][1]=a;
    }
    mergeSort(arr,0,n);
    int brr[n][3];
    int j=0, time=0;
    for(int i = 0;i<n;i++){
        if(arr[i][0]>=time){
            brr[j][0]=i+1;
            brr[j][1]=arr[i][0];
            brr[j][2]=arr[i][1];
            j++;
            time = arr[i][1];
        }
    }
    printf("Activities are\n");
    for(int i =0; i<j; i++){
        printf("a%d: Start time = %d, End Time = %d\n",brr[i][0],brr[i][1],brr[i][2]);
    }
}