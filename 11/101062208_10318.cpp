#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pat[3][3],graph[6][6],ans[30],order[30];
int d[9][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}, {0, 0}};
int min,r,c;

void dfs(int row, int cost){
    if(cost>=min)
        return;

    if(row== r*c){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(graph[i][j]==0)
                    return;
            }
        }
        min = cost;
        for(int i=0;i<min;i++)
            ans[i]=order[i];

        return;
    }
    int x=row/c ,y=row%c;
    if(x>=2 && graph[x-2][y]==0)    return;
    dfs(row+1,cost);
    for(int i=0;i<9;i++){
        int nx = x+d[i][0],ny=y+d[i][1];
         if(nx>=0 && nx<r && ny>=0 && ny<c){
            if(pat[1+d[i][0]][1+d[i][1]]==1){
                graph[nx][ny]=1-graph[nx][ny];
            }
         }
    }
    order[cost]=row;
    dfs(row+1,cost+1);
    for(int i=0;i<9;i++){
        int nx = x+d[i][0],ny=y+d[i][1];
         if(nx>=0 && nx<r && ny>=0 && ny<c){
            if(pat[1+d[i][0]][1+d[i][1]]==1){
                graph[nx][ny]=1-graph[nx][ny];
            }
         }
    }


}

int main(){
    int i,j,cas=1;
    char temp;
    while(scanf("%d%d",&r,&c)!=EOF){
        if(!r &&!c)
            break;

        for(i=0;i<6;i++){
            for(j=0;j<6;j++){
                graph[i][j]=0;
            }
        }
        scanf("%c",&temp);
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                scanf("%c",&temp);
                if(temp=='*')
                    pat[i][j]=1;
                else
                    pat[i][j]=0;

            }
            scanf("%c",&temp);
        }
        /*for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                printf("%d",pat[i][j]);
            }
            printf("\n");
        }*/
        min=99;
        dfs(0,0);
        printf("Case #%d\n",cas++);
        if(min==99)
            printf("Impossible.\n");
        else{
            for(i=0;i<min;i++){
                if(i==min-1)
                    printf("%d\n",ans[i]+1);
                else
                    printf("%d ",ans[i]+1);
            }
        }

    }



    return 0;
}
