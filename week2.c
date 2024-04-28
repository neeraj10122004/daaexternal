//Implement and Analysis factorial of a number program using iterative and recursive methods.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int iter_fact(int n){
    int ret=1;
    for(int i=1;i<=n;i++){
        ret*=i;
    }
    return ret;
}

int rec_fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*rec_fact(n-1);
    }
}
double t1,m1,t2,m2;
int main(){
    int n;
    printf("enter the num\n");
    scanf("%d",&n);
    t1=((double)(clock())/CLOCKS_PER_SEC);
    printf("%d\n",iter_fact(n));
    m1=((double)(clock())/CLOCKS_PER_SEC);
    t2=((double)(clock())/CLOCKS_PER_SEC);
    printf("\n%lf\n",m1-t1);
    printf("%d\n",rec_fact(n));
    m2=((double)(clock())/CLOCKS_PER_SEC);
    printf("\n%lf\n",m2-t2);
    return 0;
}