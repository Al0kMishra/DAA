#include<stdio.h>
#include<string.h>
void lcs(char *x,char *y,int m,int n){
    int c[m+1][n+1];
    char b[m+1][n+1];
    int i =0, j=0;
    for(i = 0;i<m+1;i++){
        c[i][0] = 0;
    }
    for(j = 0;j<n+1;j++){
        c[0][j] = 0;
    }
    for(i =1; i<m+1;i++){
        for(j=1; j<n+1; j++){
            if(x[i-1] == y[j-1]){
                c[i][j] = c[i-1][j-1] +1;
                b[i][j] = '\\';
            }
            else if(c[i-1][j] >=c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = '|';
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = '-';
            }
        }
    }
    printf("The length of longest sequence = %d\n",c[m][n]);
    int r = c[m][n];  
    char res[r+1];    
    res[r] = '\0';    

    i = m, j = n;
    while(i > 0 && j > 0) {
        if(b[i][j] == '\\') {
            res[r-1] = x[i-1];
            i--;
            j--;
            r--;
        }
        else if(b[i][j] == '-') {
            j--;
        }
        else {
            i--;
        }
    }
    printf("The Longest Common Subsequence is: %s\n", res);
}
int main(){
    char X[] ="ABCBDAB";
    char Y[] ="BDCABA";
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X,Y,m,n);
}