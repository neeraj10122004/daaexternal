#include<stdio.h>
#include<stdlib.h>

int hcf(int n,int m){
    if(m%n==0){
        return n;
    }
    else{
        return hcf(m%n,n);
    }
}
int main(){
    int n,m;
    printf("enter the nums \n");
    scanf("%d %d",&n,&m);
    int re = hcf(n,m);
    printf("\nhcf: %d lcm: %d\n",re,(n*m)/re);
    return 0;
}