#include<stdio.h>
#include<time.h>
clock_t start, end;
double cpu;
int main(){
    start = clock();
    int n;
    printf("Enter length of array: ");
    scanf("%d",&n);
    int arr[n];
    int i,a,key;
    for(i = 0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&a);
        arr[i]=a;
    }
    for(a=1;a<=n-1;a++){
        key = arr[a];
        i = a-1;
        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
    end = clock() - start;
    cpu = ((double)end)/CLOCKS_PER_SEC;
    printf("time = %f\n",cpu);
    for(i=0; i<n;i++){
        printf("%d ",arr[i]);
    }
}