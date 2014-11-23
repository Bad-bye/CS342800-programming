#include<stdio.h>
#include<stdlib.h>

struct left{
    int first;
    int second;
    int sum;
};

struct left x[1100000];

int cmp(const void *a,const void *b){
    int c,d;
    c=*(int*)a;
    d=*(int*)b;
    if(c>d) return 1;
    else if (c==d) return 0;
    else return -1;
}

int cmpx(const void *a,const void *b){
    int c,d;
    struct left e1,e2;

    e1=*(struct left*)a;
    e2=*(struct left*)b;
    if(e1.sum>e2.sum) return 1;
    else if (e1.sum==e2.sum) return 0;
    else return -1;
}
int main(){
    int a[1010];
    int m,n,i,j,k,count,y,lower,upper,mid,flag;
    int c,d;

    while(scanf("%d",&m)!=EOF){
        if(m==0) break;

        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
        }

        qsort(a,m,sizeof(int),cmp);

        for(i=0,k=0;i<m-1;i++){
            for(j=i+1;j<m;j++){
                x[k].first=a[i];
                x[k].second=a[j];
                x[k++].sum=a[i]+a[j];
            }
        }
        count=k;
        qsort(x,count,sizeof(x[0]),cmpx);

        for(flag=0,i=m-1;i>0;i--){
            for(j=0;j<i;j++){
                y=a[i]-a[j];
                upper=count-1;
                lower=0;
                while(lower<upper){
                    mid=(lower+upper)/2;
                    if(x[mid].sum==y){
                        upper=mid;
                    }
                    else if(x[mid].sum>y)
                        upper=mid-1;
                    else
                        lower=mid+1;
                }

                if(x[lower].sum==y && x[lower].first!=a[i] && x[lower].second!=a[i] && x[lower].first!=a[j] && x[lower].second!=a[j]){
                    printf("%d\n",a[i]);
                    flag=1;
                    break;
                }
                else if(x[lower+1].sum==y){
                    printf("%d\n",a[i]);
                    flag=1;
                    break;
                }



            }
            if(flag==1) break;

        }

        if(flag==0)
            printf("no solution\n");



    }
    return 0;
}
