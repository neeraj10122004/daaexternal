#include <limits.h>
#include<stdio.h>
#include<stdlib.h>
int dim[100];
int cost[100][100];
int kk[100][100];

void matrix_chain(int n){
    for(int i=1;i<n;i++){
        cost[i][i]=0;
    }
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            cost[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int q=cost[i][k]+cost[k+1][j]+(dim[i-1]*dim[k]*dim[j]);
                if(q<cost[i][j]){
                    cost[i][j]=q;
                    kk[i][j]=k;
                }
            }
        }
    }
}

void pattern(int i,int j){
    if(i==j){
        printf("A%d",i);
    }
    else{
        printf("(");
        pattern(i,kk[i][j]);
        pattern(kk[i][j]+1,j);
        printf(")");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&dim[i]);
    }
    matrix_chain(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
    printf("\n%d\n",cost[1][n-1]);

    pattern(1,n-1);

    return 0;
}

