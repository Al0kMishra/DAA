#include<stdio.h>
#include<time.h>
#include<stdlib.h>
clock_t start, end;
double cpu;
void Randomint(int *arr,int count){ 
    for (int i=0;i<count;i++)
        arr[i]=(rand()%100)+1;
}
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c; 
}
int partition(int a[], int p, int r){
    int x=a[r];
    int i = p-1;
    int j;
    for(j=p;j<r;j++){
        if(a[j]<=x){
            i=i+1;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return(i+1);
}
void quicksort(int a[], int p, int r){
    if(p<r){
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int main(){
    start = clock();
    int i;
    int arr[10000];
    Randomint(arr,10000);
    quicksort(arr,0,9999);
    end = clock() - start;
    cpu = ((double)end)/CLOCKS_PER_SEC;
    printf("time = %f\n",cpu);
}