#include<stdio.h>
#include<time.h>
int main(){
    clock_t time;
    time = clock();
    int n =1000;
    int i = 1;
    int s = 1;
    while(s<=n){
        i++;
        s = s+1;
        printf("UPES\n");  
    }
    time = clock() - time;
    double timetaken = ((double)time)/CLOCKS_PER_SEC;
    printf("time = %.50f",timetaken);  
}