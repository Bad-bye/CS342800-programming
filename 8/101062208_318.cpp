#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
struct node{
    int a,b;
    double len;
};

node e[30000];
double edge[510][510],d[510];
int m,n,q[510],pre[510];

int main(){
    int i,j,a,b,c,u,flag,cas=1,ansi;
    double temp,ans;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m==0 && n==0)
            break;
        for(i=1;i<=m;i++){
            q[i]=1;
            d[i]=2e9;
            for(j=1;j<=m;j++)
                edge[i][j]=2e9;
        }
        d[1]=0;
        for(i=0;i<n;i++){
            scanf("%d%d%d",&a,&b,&c);
            edge[a][b]=c;
            edge[b][a]=c;
            if(a>b){
                e[i].a=b;
                e[i].b=a;
            }
            else{
                e[i].a=a;
                e[i].b=b;
            }
            e[i].len=c;
        }
        for(j=0;j<m;j++){
            for(i=1,temp=2e9;i<=m;i++){
                if(d[i]<temp && q[i]==1){
                    temp=d[i];
                    u=i;
                }
            }
            q[u]=0;
            for(i=1;i<=m;i++){
                if(d[i]>d[u]+edge[u][i]){
                    d[i]=d[u]+edge[u][i];
                    pre[i]=u;
                }
            }

        }

        for(i=1,ans=0.0;i<=m;i++){
            if(d[i]>ans){
                ans=d[i];
                ansi=i;
            }
        }
        for(i=0,flag=0;i<n;i++){
            temp=(d[e[i].a]+d[e[i].b]+e[i].len)/2;
            if(temp>ans){
                flag=i;
                ans=temp;
            }
        }
        if(ans==0.0){
            printf("System #%d\n",cas++);
            printf("The last domino falls after 0.0 seconds, at key domino 1.\n\n");
        }
        else if(flag==0){
            printf("System #%d\n",cas++);
            printf("The last domino falls after %.1f seconds, at key domino %d.\n\n",ans,ansi);
        }
        else{
            printf("System #%d\n",cas++);
            printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n\n",ans,e[flag].a,e[flag].b);
        }


    }





    return 0;
}
