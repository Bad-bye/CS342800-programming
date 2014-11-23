#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>

int prime[110000],temp[100000];
int p_num,tempnum;
int isprime(int n){
    if(n==1){
        return 0;
    }
    int m=(int)(sqrt(n)+0.001);
    for(int i=0;prime[i]<=m && i<p_num;i++){
        if((n%prime[i])==0)
            return 0;
    }
    return 1;
}

int main(){
    int lower,upper,max,min,max1,max2,min1,min2,temp1;
    int i=0;
    prime[0]=2;
    p_num=1;
    for(i=3;i<=100000;i++){
        if(isprime(i)){
            prime[p_num]=i;
            p_num++;
        }
    }
    while(scanf("%d%d",&lower,&upper)!=EOF){
        for(i=lower,tempnum=0;i<=upper;i++){
            if(isprime(i)){
                temp[tempnum]=i;
                tempnum++;
            }
            if(i==upper)
                break;
        }

        if(tempnum<2){
            printf("There are no adjacent primes.\n");
            continue;
        }

        for(max=0,i=1,min=9999999;i<tempnum;i++){
                temp1=temp[i]-temp[i-1];
                if(max<temp1){
                    max=temp1;
                    max1=temp[i-1];
                    max2=temp[i];
                }
                if(min>temp1){
                    min=temp1;
                    min1=temp[i-1];
                    min2=temp[i];
                }

        }
        printf("%d,%d are closest, %d,%d are most distant.\n",min1,min2,max1,max2);


    }

    return 0;
}
