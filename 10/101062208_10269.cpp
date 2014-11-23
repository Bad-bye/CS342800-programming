#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node
{
    int u,cost,k;
};

int A,B,M,L,K;
int graph[110][110],dis[110][20];


int main(){
    freopen("10269.in","r",stdin);
    int T,i,j,k,ans;
    int a,b,c;
    scanf("%d",&T);
    while(T--){
        for(i=0;i<110;i++){
            for(j=0;j<110;j++){
                graph[i][j]=999999;
            }
            for(j=0;j<20;j++)
                dis[i][j]=999999;
        }
        scanf("%d%d%d%d%d",&A,&B,&M,&L,&K);
        for(i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            graph[a][b]=c;
            graph[b][a]=c;
        }

        for(k=1;k<=A;k++){
            for(i=1;i<=A+B;i++){
                for(j=1;j<=A+B;j++){
                    if(graph[i][j]>graph[i][k]+graph[k][j])
                        graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }

        queue<node> q;
        node temp,temp1;
        temp.cost=0;
        temp.k=K;
        temp.u=A+B;
        q.push(temp);
        dis[A+B][K]=0;
        while(!q.empty()){
            temp = q.front();
            q.pop();

            for(i=1;i<=A+B;i++){
                if(graph[temp.u][i]!=999999 && temp.u!=i){
                    if(graph[temp.u][i]<=L && dis[i][temp.k-1]>temp.cost && temp.k>0 ){
                        dis[i][temp.k-1]=temp.cost;
                        temp1.u=i;
                        temp1.cost=temp.cost;
                        temp1.k=temp.k-1;
                        q.push(temp1);
                    }
                    if( dis[i][temp.k] > temp.cost+graph[temp.u][i]){
                        dis[i][temp.k]=temp.cost+graph[temp.u][i];
                        temp1.u=i;
                        temp1.cost=temp.cost+graph[temp.u][i];
                        temp1.k=temp.k;
                        q.push(temp1);
                    }
                }
            }

        }
        for(i=0,ans=999999;i<=K;i++){
            if(ans>dis[1][i])
                ans=dis[1][i];
        }
        printf("%d\n",ans);

    }




    return 0;
}
