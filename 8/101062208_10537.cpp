#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

queue<int> q;
long long graph[100][100],d[100],n,req;
int from,to,old[100];




int main(){

    int i,j,a1,a2,now,next,cas=1;
    char c1,c2,c;
    long long temp,temp1;
    while(scanf("%lld%c",&n,&c)!=EOF && n!=-1){
        if(n==-1)
        break;
        for(i=0;i<100;i++){
            d[i]=99999999999;
            for(j=0;j<100;j++)
                graph[i][j]=0;
        }
        for(i=0;i<n;i++){
            scanf("%c %c%c",&c1,&c2,&c);
            if(c1>='A' && c1<='Z')
                a1=c1-'A';
            else
                a1=c1-'a'+26;

            if(c2>='A' && c2<='Z')
                a2=c2-'A';
            else
                a2=c2-'a'+26;


            graph[a1][a2]=1;
            graph[a2][a1]=1;
        }
        scanf("%lld %c %c",&req,&c1,&c2);
        if(c1>='A' && c1<='Z')
            from=c1-'A';
        else
            from=c1-'a'+26;

        if(c2>='A' && c2<='Z')
            to=c2-'A';
        else
            to=c2-'a'+26;

        q.push(to);
        d[to]=req;

        while(!q.empty()){
            now=q.front();
            q.pop();
            for(i=0;i<100;i++){
                if(graph[now][i]==1){
                    if(now<26){
                    temp=0;
                       while((d[now]+temp)-(d[now]+temp)/20-((d[now]+temp)%20==0?0:1)<d[now]){
                            temp+=d[now]-((d[now]+temp)-(d[now]+temp)/20-((d[now]+temp)%20==0?0:1));
                        }
                        temp+=d[now];
                    }
                    else{
                        temp=d[now]+1;
                    }

                    if(d[i]>temp){
                        d[i]=temp;
                        old[i]=now;
                        q.push(i);
                    }
                    else if(d[i]==temp){
                        if(old[i]>now){
                            old[i]=now;
                        }
                    }

                }
            }
        }

        printf("Case %d:\n",cas++);
        printf("%lld\n",d[from]);
        for(i=from;;){
            if(i<26)
                c1='A'+i;
            else
                c1='a'+i-26;
            if(i==to){
                printf("%c\n",c1);
                break;
            }
            printf("%c-",c1);
            i=old[i];
        }



    }
    return 0;


}
