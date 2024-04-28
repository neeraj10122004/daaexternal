//Implement Selection sort and find how many steps are required to sort 10 elements.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double tt,mm;
int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    int step=0;
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    tt=((double)(clock())/CLOCKS_PER_SEC);
    for(int i=0;i<10;i++){
        int min=arr[i];
        int k=i;
        for(int j=i;j<10;j++){
            if(arr[j]<min){
                min=arr[j];
                k=j;
            }
        }
        if(min!=arr[i]){
            int tem=arr[i];
            arr[i]=arr[k];
            arr[k]=tem;
            step++;
        }
    }
    for(int i=0;i<1000000000;i++);
    mm=((double)(clock())/CLOCKS_PER_SEC);
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n%d time: %lf",step,mm-tt);
    return 0;
}