#include<stdio.h>
#include<time.h>
clock_t start, end;
double cpu;
int main(){
    start = clock();
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        i=i*2;
    }
    end = clock() - start;
    cpu = ((double)end)/CLOCKS_PER_SEC;
    printf("time = %f",cpu);

}