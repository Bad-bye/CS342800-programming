#include<stdio.h>
int num1[500000];
int t;


void big_mul(int *a,int b){
    int i,j,carry;
    t=1;
    for(i=1;i<=b;i++){
        carry=0;
        for(j=0;j<t;j++){
            a[j]=i*a[j]+carry;
            carry=a[j]/10000;
            a[j]=a[j]%10000;
        }
        if(carry>0){
            a[t]=carry;
            t++;
        }
    }
}

int main(){
    int x,temp,temp2,carry;
    int i,j;


    while(scanf("%d",&x)!=EOF){
        printf("%d!\n",x);

        for(i=0;i<500000;i++){
            num1[i]=0;
        }
        num1[0]=1;
        big_mul(num1,x);
        printf("%d",num1[t-1]);


        for(i=t-2;i>=0;i--){
            printf("%04d",num1[i]);
        }
        printf("\n");





    }
    return 0;


}
