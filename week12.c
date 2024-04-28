#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int n,int m){
    if(n>m){
        return n;
    }
    return m;
}
int lcs(char* a,char* b,int n,int m,char* ret){
    int matrix[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                matrix[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                matrix[i][j]=matrix[i-1][j-1]+1;
            }
            else{
                matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
            }
        }
    }
    int key=matrix[n][m];
    ret[key]='\0';
    int x=n;
    int y=m;
    while(x>0 && y>0){
        if(a[x-1]==b[y-1]){
            ret[key-1]=a[x-1];
            x--;
            y--;
            key--;
        }
        else if(matrix[x-1][y]>matrix[x][y-1]){
            x--;
        }
        else{
            y--;
        }
    }
    return matrix[n][m];
}
int main(){
    char a[100];
    char b[100];
    scanf("%s",&a);
    scanf("%s",&b);
    int n=strlen(a);
    int m=strlen(b);
    char ret[n+m];
    int max_len = lcs(a,b,n,m,ret);
    printf("%d is max length\nlcs string is %s\n",max_len,ret);
    return 0;
}