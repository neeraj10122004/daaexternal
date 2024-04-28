#include<stdio.h>
#include<stdlib.h>

void swap(float* a,float* b){
    float temp=*b;
    *b=*a;
    *a=temp;
}
int main(){
    int n;
    scanf("%d",&n);
    float profits[n];
    float weights[n];
    float pw_ratio[n];
    float x[n];
    int max_weight;
    scanf("%d",&max_weight);
    for(int i=0;i<n;i++){
        scanf("%f %f",&profits[i],&weights[i]);
        pw_ratio[i]=profits[i]/weights[i];
        x[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(pw_ratio[j]>pw_ratio[i]){
                swap(&pw_ratio[i],&pw_ratio[j]);
                swap(&profits[i],&profits[j]);
                swap(&weights[i],&weights[j]);
            }
            else if(pw_ratio[i]==pw_ratio[j]){
                if(profits[j]>profits[i]){
                    swap(&pw_ratio[i],&pw_ratio[j]);
                    swap(&profits[i],&profits[j]);
                    swap(&weights[i],&weights[j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(weights[i]<max_weight){
            max_weight-=weights[i];
            x[i]=1;
        }
        else{
            x[i]=max_weight/weights[i];
            break;
        }
    }
    for(int i=0;i<n;i++){
        printf("%f %f %f %f\n",profits[i],weights[i],pw_ratio[i],x[i]);
    }
    float re=0,rew=0;
    for(int i=0;i<n;i++){
        re+=profits[i]*x[i];
        rew+=weights[i]*x[i];
    }
    printf("\n%f %f\n",re,rew);
    return 0;
}