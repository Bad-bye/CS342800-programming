#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
using namespace std;

vector<int>  v[30010];
int count,ans;
int m,n;
int visit[30010];


void dfs(int index){
    visit[index]=1;
    if(v[index].size()==0) return ;
    for(int i=0;i<v[index].size();i++){
        if(visit[v[index][i]]==0){
            count++;
            dfs(v[index][i]);
        }
    }
}



int main(){
    int x;
    int i,j,k;
    scanf("%d",&x);
    while(x--){
        for(i=0;i<30010;i++){
            v[i].clear();
            visit[i]=0;
        }
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&j,&k);
            v[j].push_back(k);
            v[k].push_back(j);
        }
        for(i=1,ans=0;i<=m;i++){
            if(visit[i]==0){
                count=1;
                dfs(i);
                if(count>ans)
                    ans=count;
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}
