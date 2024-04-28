#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

int main(){
    int n;
    scanf("%d",&n);
    int mat[n][n];
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int t=0;
    visited[0]=true;
    while(t<n-1){
        int min=INT_MAX;
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i] && !visited[j] && mat[i][j]){
                    if(mat[i][j]<min){
                        min=mat[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }
        printf("%d - %d - %d \n",x,y,mat[x][y]);
        visited[y]=true;
        t+=1;
    }
    return 0;
}