#include<stdio.h>
#include<stdlib.h>
#define r1 2
#define r2 2
#define c1 2
#define c2 2
void multimatrix(int arr[r1][c1],int brr[r2][c2],int crr[r1][c2]){;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            crr[i][j]=0;
            for(int k=0;k<c1;k++){
                crr[i][j] += arr[i][k]* brr[k][j];
            }
        }
    }
}

int main(){
    int arr[r1][c1] ={{1,2},{3,4}};
    int brr[r2][c2] = {{5,6},{7,8}};
    int crr[r1][c2];
    multimatrix(arr,brr,crr);
    for(int i =0;i<r1;i++){
        printf("| ");
        for(int j=0;j<c2;j++){
            printf("%d ",crr[i][j]);
        }
        printf("|\n");
    }

}