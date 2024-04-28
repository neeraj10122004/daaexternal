#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char a[100];
    char b[100];
    printf("enter the strings \n");
    scanf("%s",&a);
    scanf("%s",&b);
    int n=strlen(a);
    int m=strlen(b);
    n=(n>m)? n:m;
    
    int ret=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            ret++;
        }
    }
    printf("\n%d\n",ret);
    return 0;
}