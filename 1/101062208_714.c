#include<stdio.h>

int a[600];
int cut[600];


int check(long long int mid,long long int m,long long int n){
    long long int tempsum=0;
    long long int count,i;
    for(i=0,count=1;i<m;i++){
        tempsum+=a[i];
        if(tempsum>mid){
        count++;
        tempsum=a[i];
        }
    }
    if(count<=n)return 1;
    else return 0;

}


int main(){
    long long int lower,upper,mid,sum,test;
    int x,m,n,i,j;

    scanf("%d",&x);

    while(x!=0){
        scanf("%d %d",&m,&n);
        lower=0;

        for(sum=0,i=0;i<m;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            //if(lower<a[i]) lower=a[i];
        }

        for(i=0;i<600;i++)
            cut[i]=0;

        upper=sum;


        while(lower<upper){
               /* printf("%lld  %lld\n", lower, upper);
                system("pause");*/
            mid=(lower+upper)/2;
            if(check(mid,m,n)==1){
                upper=mid;
            }
            else{
                lower=mid+1;
            }

        }

        printf("%lld\n",lower);


        for(i=m-1,j=n-1,test=0;i>=0;i--){
            if(i+1>j && test + a[i]<=lower){
                test+=a[i];
            }
            else if(a[i]>lower){
                cut[i-1]=1;
                test=0;
                j--;
            }
            else{
                cut[i]=1;
                test=a[i];
                j--;
            }
        }


        for(i=0;i<m;i++){

            if(cut[i]){
                printf("%d /",a[i]);
            }
            else
                printf("%d",a[i]);

            if(i!=m-1)
                printf(" ");
        }
        printf("\n");
        x--;

    }


    return 0;

}
