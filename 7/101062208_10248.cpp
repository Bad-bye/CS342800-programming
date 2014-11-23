#include<stdio.h>
#include<stdlib.h>
int indegree[10],outdegree[10],graph[10][10],check[10],first,ans[1000],num;

void dfs(int node){
    printf("%d",node);
    check[node]=0;
    if(graph[node][node]){
         outdegree[node]--, indegree[node]--;
         graph[node][node]--;
         dfs(node);
         return;

    }
    for(int i=1; i<10;i++) {
        if(i==node){
            continue;
        }
        if(graph[node][i]) {
            outdegree[node]--, indegree[i]--;
            graph[node][i]--;
            dfs(i);
            return;
        }
    }
    if(graph[node][0]){
        outdegree[node]--, indegree[0]--;
        graph[node][0]--;
        dfs(0);
    }
}


int main(){
    int m,n,a,b;
    int i,j;
    while(scanf("%d%d",&m,&n)!=EOF){
        for(i=0;i<10;i++){
            check[i]=0;
            indegree[i]=0;
            outdegree[i]=0;
            for(j=0;j<10;j++){
                graph[i][j]=0;
            }
        }
        for(i=m;i<=n;i++){
            if(i>=10){
                a=i/10,b=i%10;
                graph[a][b]=1;
                outdegree[a]++,indegree[b]++;
            }
            else{
                check[i]=1;
            }
        }

        for(i=1;i<10;i++){
            if(outdegree[i]>indegree[i]){
                dfs(i);
                i=0;
            }
        }
        for(i=1;i<10;i++){
            if(outdegree[i] || indegree[i]){
                dfs(i);
            }
        }
        for(i=1;i<10;i++){
            if(check[i])
                printf("%d",i);
        }
        printf("\n");
    }


    return 0;
}
