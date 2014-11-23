#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<string.h>
using namespace std;

struct node{
    int x,y,dir;
};

node pre[10][10][5],now;
char name[30];
int graph[10][10][5][5],visit[10][10][5];
int dir[5][2]= {{0,0},{1,0},{0,-1},{-1,0},{0,1}};

int get_dir(char c){
    if(c=='S') return 1;
    else if(c=='W') return 2;
    else if(c=='N') return 3;
    else if(c=='E') return 4;
}

int main(){
    int i,j,k,l,temp,temp1,flag;
    int fx,fy,ex,ey,nx,ny,ndir,x,y;
    char c,str[5];

    while(scanf("%s",&name)!=EOF){
        if(strcmp(name,"END")==0)
            break;

        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                for(k=0;k<5;k++){
                        visit[i][j][k]=0;
                    for(l=0;l<5;l++){
                        graph[i][j][k][l]=0;
                    }
                }
            }
        }

        scanf("%d %d %c %d %d",&fx,&fy,&c,&ex,&ey);
        temp=get_dir(c);
        graph[fx][fy][0][temp]=1;
        while(scanf("%d",&x)!=EOF){
           if(x==0)
                break;
           scanf("%d",&y);
           while(scanf("%s",&str)!=EOF){
                if(str[0]=='*')
                    break;

                int len = strlen(str);
                temp=get_dir(str[0]);
                for(i=1;i<len;i++){
                     //printf("GG %s\n",str);
                     if(str[i]=='F')
                        graph[x][y][temp][temp] = 1;
                     else if(str[i]=='L'){
                        if(temp==1)
                            graph[x][y][temp][4] = 1;
                        else
                            graph[x][y][temp][temp-1] = 1;
                     }
                     else{
                        if(temp==4)
                            graph[x][y][temp][1] = 1;
                        else
                            graph[x][y][temp][temp+1] = 1;
                     }
                }

           }
        }

        queue<int> q;
        q.push(fx);
        q.push(fy);
        q.push(0);
        flag=0;

        while(!q.empty()){
            x = q.front();  q.pop();
            y = q.front();  q.pop();
            temp = q.front();  q.pop();
            if(x==ex && y==ey){
                flag=1;
                break;
            }

            for(i=1;i<5;i++){
                if(graph[x][y][temp][i]==1){
                    nx=x+dir[i][0];
                    ny=y+dir[i][1];
                    if(nx>0 && nx<10 && ny>0 && ny<10){
                        if(visit[nx][ny][i]==0){
                            visit[nx][ny][i]=1;
                            pre[nx][ny][i].x=x;
                            pre[nx][ny][i].y=y;
                            pre[nx][ny][i].dir=temp;
                            q.push(nx);
                            q.push(ny);
                            q.push(i);
                        }
                    }
                }
            }

        }
        printf("%s\n",name);
        if(flag){
            x=ex;
            y=ey;
            stack<int> stk;
            while(temp!=0){
                stk.push(x);
                stk.push(y);
                nx = pre[x][y][temp].x;
                ny = pre[x][y][temp].y;
                ndir = pre[x][y][temp].dir;
                x = nx;
                y = ny;
                temp = ndir;
            }
            stk.push(fx);
            stk.push(fy);
            int count=0;
            printf(" ");
            while(!stk.empty()){
                y=stk.top(); stk.pop();
                x=stk.top(); stk.pop();
                if(count && count==10){
                    printf("\n ");
                    count = 0;
                }
                printf(" (%d,%d)",x,y);
                count++;
            }
            printf("\n");
        }
        else
            printf("  No Solution Possible\n");



    }




    return 0;
}
