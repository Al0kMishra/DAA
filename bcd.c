#include<stdio.h>
#include<time.h>
clock_t start, end;
double cpu;
float algo(int *a, int n){
    int i;
    int sum = 0;
    for(i=0;i<n;i++){
        sum = sum + *(a+i);
    }
    return sum;
    
}
int main(){
    start = clock();
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
    printf("%f = sum\n",algo(arr,n));
    end = clock() - start;
    cpu = ((double)end)/CLOCKS_PER_SEC;
    printf("time = %.20f",cpu);
    
    

}
