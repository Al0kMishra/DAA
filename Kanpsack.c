#include<stdio.h>
#define W 60

void merge(int arr[][2], int p, int q, int r){
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
    while (i < n1 && j < n2){
        float ratioa = (float)a[i][1] / a[i][0];
        float ratiob = (float)b[j][1] / b[j][0];

        if (ratioa >= ratiob){
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

    while (j < n2) {
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
    printf("Enter the number of Items: ");
    scanf("%d",&n);
    int arr[n][2] ;
    for(int i=0; i<n;i++){
        printf("Enter a%d weight: ",i+1);
        scanf("%d",&a);
        arr[i][0]=a;
        printf("Enter a%d Value: ",i+1);
        scanf("%d",&a);
        arr[i][1]=a;
    }
    mergeSort(arr,0,n);
    int weight =0, profit = 0;
    int i=0;
    while(weight<W){
        if((W-weight)>arr[i][0]){
            profit = profit +arr[i][1];
            weight = weight + arr[i][0];
            i++;
        }
        else if((W-weight)<arr[i][0]){
            float a = (float)(W-weight)/arr[i][0];
            profit = profit +(a*arr[i][1]);
            weight = weight+(W-weight);
        }
    }
    printf("Profit= %d ",profit);    
}
