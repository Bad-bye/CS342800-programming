#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int map[110][110],visit[110],n,len,ans;

int check(){
    for(int i=1;i<=n;i++){
        if(visit[i]==0)
            return 1;
    }
    return 0;
}

void dfs(int x){
    visit[x]=1;
    for(int i=1;i<=n;i++){
        if(map[x][i] && visit[i]==0){
            dfs(i);
        }
    }
}


int main(){
    int i,j,a,b,flag;
    char c;
    while(scanf("%d%c",&n,&c)!=EOF && n){
        for(i=0;i<110;i++){
            for(j=0;j<110;j++)
                map[i][j]=0;
        }
        while(scanf("%d",&a)!=EOF && a){
            while(scanf("%d%c",&b,&c)!=EOF){
                map[a][b]=1;
                map[b][a]=1;
                if(c=='\n')
                    break;
            }
        }
        for( i=1,ans=0;i<=n;i++){
            for(j=1;j<=n;j++)
                visit[j]=0;
            visit[i]=1;
            if(i==2)
                dfs(1);
            else
                dfs(2);
            flag=check();
            ans+=flag;

        }
        printf("%d\n",ans);

    }




    return 0;
}
