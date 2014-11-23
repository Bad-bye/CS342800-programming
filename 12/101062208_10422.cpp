#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
using namespace std;


int ans,count;
int graph[5][5];
int dir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
int fir[5][5] = {
{1,1,1,1,1},
{0,1,1,1,1},
{0,0,2,1,1},
{0,0,0,0,1},
{0,0,0,0,0}
};
void dfs(int x,int y,int step){
    int flag;
    if(step>10) return;
    flag=1;
    for(int i=0;i<5 && flag;i++){
        for(int j=0;j<5;j++){
            if(graph[i][j]!=fir[i][j]){
                flag=0;
                break;
            }
        }
    }
    if(flag){
        if(ans>step)
            ans=step;
        return;
    }

    for (int i=0;i<8;i++) {
        if (dir[i][0]+x <0||dir[i][0]+x>= 5)
            continue;
        if (dir[i][1]+y < 0 || dir[i][1]+y >= 5)
            continue;
        swap(graph[x][y],graph[dir[i][0]+x][dir[i][1]+y]);
        dfs(x+dir[i][0] , y+dir[i][1] ,step+1);
        swap(graph[x][y],graph[dir[i][0]+x][dir[i][1]+y]);
    }

}

int main(){
    int T,i,j,x,y;
    char temp;
    scanf("%d",&T);
    scanf("%c",&temp);
    while(T--){
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                scanf("%c",&temp);
                if(temp==' '){
                    x=i;
                    y=j;
                    graph[i][j]=2;
                }
                else if(temp=='0')
                    graph[i][j]=0;
                else
                    graph[i][j]=1;
            }
            scanf("%c",&temp);
        }

        ans=99;
        dfs(x,y,0);
        if(ans==99)
            printf("Unsolvable in less than 11 move(s).\n");
        else
            printf("Solvable in %d move(s).\n",ans);


    }




    return 0;
}
