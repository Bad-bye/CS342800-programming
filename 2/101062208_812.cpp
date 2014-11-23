#include<stdio.h>
#include<stdlib.h>
#include<set>
using namespace std;

set<int> ans;
set<int>::iterator iter;
int w;



int box[60][30],num[60];


void dfs(int i,int sum){
    if(i==w){
        ans.insert(sum);
        return;
    }
    else{
        for(int j=0;j<num[i];j++){
            dfs(i+1,sum+box[i][j]);
        }
    }
}



int main(){
    int i,j,k,c=1;
    int b[50];
    int temp,maxn,maxp,maxpp,sum,count;

    while(scanf("%d",&w)!=EOF){
        if(w==0)
            break;

        if(c!=1){
            printf("\n");
        }

        ans.clear();

        printf("Workyards %d\n",c++);

        for(i=0,maxp=0;i<w;i++){
            scanf("%d",&b[i]);
            for(j=0,maxpp=0,sum=0,num[i]=1,box[i][0]=0;j<b[i];j++){
                scanf("%d",&temp);
                sum+=10-temp;
                if(sum>maxpp){
                    maxpp=sum;
                    num[i]=1;
                    box[i][0]=j+1;
                }
                else if(sum==maxpp){
                    k=num[i];
                    box[i][k]=j+1;
                    num[i]++;
                }

            }
            maxp+=maxpp;

        }
        printf("Maximum profit is %d.\n",maxp);
        dfs(0,0);

        printf("Number of pruls to buy:");

        for(iter=ans.begin(),count=0; iter!=ans.end() && count<10 ; iter++,count++){
            printf(" %d",*iter);
        }
        printf("\n");

    }

    return 0;

}
