


#include<stdio.h>
#include<stdlib.h>
#include<cmath>

int prime[100000];
int p_num;
bool isprime(int n){
    int m=(int)(sqrt(n)+0.001);
    for(int i=0;prime[i]<=m && i<p_num;i++){
        if((n%prime[i])==0)
            return false;
    }
    return true;
}


int main(){
    int x;
    int i,j;
    int lower,upper,max,temp,temp1,cnt,m,maxnum;
    prime[0]=2;
    p_num=1;
    for(i=3;i<=100000;i++){
        if(isprime(i)==true){
            prime[p_num]=i;
            p_num++;
        }
    }
    scanf("%d",&x);
    while(x>0){
        scanf("%d%d",&lower,&upper);
        for(i=lower,max=0,temp=1;i<=upper;i++){
            for(j=0;prime[j]<=i,j<p_num;j++){
                for(cnt=0,temp1=i;;){
                    if(temp1%prime[j]==0){
                        cnt++;
                        temp1/=prime[j];
                    }
                    else
                        break;
                }
                temp*=(cnt+1);
            }
            if(i==1)
                temp=1;
            else if(temp==1)
                temp=2;
            if(temp>max){
                max=temp;
                maxnum=i;
            }
            temp=1;

        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",lower,upper,maxnum,max);
        x--;

    }
    return 0;
}

