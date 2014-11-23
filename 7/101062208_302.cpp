#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;

struct node{
    int x,y,visit,id;
};

stack<int> stk;
struct node street[2000];
int cnt,flag,ans[2000],first,map[50][50],degree[2000];
void dfs(int i , int id){
    int j;
    if(degree[i]==0){
        stk.push(id);
        return;
    }
    for(j=1;j<=cnt;j++){
        if(street[j].x == i && street[j].visit==0){
            degree[i]--;
            degree[street[j].y]--;
            street[j].visit=1;
            dfs(street[j].y,j);
        }
        else if(street[j].y == i && street[j].visit==0){
            degree[i]--;
            degree[street[j].x]--;
            street[j].visit=1;
            dfs(street[j].x,j);
        }
    }
    stk.push(id);
}

int main(){
    int x,y,z;
    int i,j;
    cnt=0;
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x==0 && y==0){
            if(cnt==0)
                break;
            for(i=0,flag=0;i<50;i++){
                if(degree[i]%2==1){
                    flag=1;
                    break;
                }
            }
            if(flag){
                printf("Round trip does not exist.\n\n");
                cnt=0;
                for(i=0;i<50;i++)
                    degree[i]=0;
                continue;

            }
            dfs(first,0);
            stk.pop();
            for(i=0;i<cnt;i++){
                j=stk.top();
                stk.pop();
                ans[i]=j;
            }
            if(street[j].x==first || street[j].y==first)
                flag=1;
            else
                flag=0;
            if(flag){
                for(i=0;i<cnt;i++){
                    if(i==0)
                        printf("%d",ans[i]);
                    else
                        printf(" %d",ans[i]);
                }
                printf("\n\n");
            }
            else{
                printf("Round trip does not exist.\n\n");
            }
            cnt=0;
            for(i=0;i<50;i++)
                degree[i]=0;
            continue;
        }
        if(cnt==0){
            if(x>y)
                first=y;
            else
                first=x;
        }
        scanf("%d",&z);
        street[z].x=x,street[z].y=y,street[z].visit=0;
        degree[x]++;
        degree[y]++;
        cnt++;

    }

    return 0;
}
