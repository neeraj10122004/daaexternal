#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("enter the size\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key && j>=0){

            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}