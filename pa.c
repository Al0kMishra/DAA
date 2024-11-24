#include<stdio.h>

void merge_teams(int arr[][2],int p,int q,int r) {
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int L[n1][2],R[n2][2];
    for(i=0;i<n1;i++){
        L[i][0]=arr[p+i][0];
        L[i][1]=arr[p+i][1];
    }
    for(j=0;j<n2;j++){
        R[j][0]=arr[q+1+j][0];
        R[j][1]=arr[q+1+j][1];
    }
    i=j=0;
    k=p;
    while(i<n1 && j<n2) {
        if(L[i][1]>R[j][1]){
            arr[k][0]=L[i][0];
            arr[k][1]=L[i][1];        
            i++;
        }
        else{
            arr[k][0]=R[j][0];
            arr[k][1]=R[j][1];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k][0]=L[i][0];
        arr[k][1]=L[i][1];
        i++;
        k++;
    }
    while(j<n2){
        arr[k][0]=R[j][0];
        arr[k][1]=R[j][1];
        j++;
        k++;
    }
}
void merge_sort_teams(int arr[][2],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort_teams(arr,p,q);
        merge_sort_teams(arr,q+1,r);
        merge_teams(arr,p,q,r);
    }
}
void merge_tasks(int *arr,int p,int q,int r) {
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[p+i];
    for(j=0;j<n2;j++)
        R[j]=arr[q+1+j];
    
    i=j=0;
    k=p;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void merge_sort_tasks(int *arr,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort_tasks(arr,p,q);
        merge_sort_tasks(arr,q+1,r);
        merge_tasks(arr,p,q,r);
    }
}

void assign_tasks(int teams[][2],int no_teams,int tasks[],int no_tasks){
    merge_sort_teams(teams,0,no_teams-1);
    merge_sort_tasks(tasks,0,no_tasks-1);
    int count=0;
    for(int i=0;i<no_teams && count<no_tasks;i++){
        printf("Team ID %d with capacity %d assigned with:\n",teams[i][0],teams[i][1]);
        for(int j=0;j<teams[i][1] && count<no_tasks;j++){
            printf("Priority %d\n",tasks[count]);
            count++;
        }
        printf("\n");
    }
    if(count<no_tasks){
        printf("Remaining tasks:\n");
        for(int i=count;i<no_tasks;i++){
            printf("Priority %d\n", tasks[i]);
        }
    }
}


int main() {
    int no_teams = 3;
    int teams[3][2] = {{1, 5}, {2, 3}, {3, 7}}; 
    int tasks[] = {1, 4, 2, 10, 6, 3, 7, 8};
    int no_tasks = sizeof(tasks) / sizeof(tasks[0]);

    assign_tasks(teams,no_teams,tasks,no_tasks);
}