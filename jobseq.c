#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 4
void merge(int arr[max][3],int p,int q,int r) {
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
        if(a[i][2]>=b[j][2]){
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
void merge_sort(int arr[max][3],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int min(int a,int b){
    return (a<b)? a:b;
}
int main(){
    int arr[max][3]={{1,2,100},{2,1,10},{3,2,15},{4,1,27}};
    merge_sort(arr,0,max-1);
    int result[max];
    bool slot[max];
    for(int i=0;i<max;i++)
        slot[i]=false;
    for(int i=0;i<max;i++){
        for(int j=min(max,arr[i][1])-1;j>=0;j--){
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }

    for(int i=0;i<max;i++){
        if(slot[i])
            printf("%d ",arr[result[i]][0]);
    }
}
