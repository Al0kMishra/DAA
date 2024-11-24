#include<stdio.h>
#include<time.h>
clock_t start, end;
double cpu;
int main(){
    start = clock();
    int a,b,c;
    printf("Enter number: ");
    scanf("%d",&a);
    printf("Enter number: ");
    scanf("%d",&b);
    c=a;
    a=b;
    b=c;
    end = clock() - start;
    cpu = ((double)end)/CLOCKS_PER_SEC;
    printf("time = %f\n",cpu);
    printf("Numbers a = %d, b = %d",a,b);
}