#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char name[30][30],str1[30],str2[30];
int m,n,count,visit[30],graph[30][30];

int search(char str[30]){
   int i;
   for(i=0; i<count; i++)
      if(strcmp(str,name[i])==0) return i;
   strcpy(name[i],str);
   count++;
   return i;
}

int main(){
    int i,j,k,cas=1,a,b;

    while(scanf("%d%d",&m,&n)!=EOF && m){
        for(i=0;i<30;i++){
            visit[i]=0;
            for(j=0;j<30;j++){
                graph[i][j]=0;
            }
        }

        for(i=0,count=0;i<n;i++){
            scanf("%s%s",&str1,&str2);
            a=search(str1);
            b=search(str2);
            graph[a][b]=1;
        }

        for(k=0;k<count;k++){
            for(i=0;i<count;i++){
                for(j=0;j<count;j++){
                    if(graph[i][k] && graph[k][j])
                        graph[i][j]=1;
                }
            }
        }

        printf("Calling circles for data set %d:\n",cas++);
        for(i=0;i<m;i++){
            if(!visit[i]){
                visit[i]=1;
                printf("%s",name[i]);
                for(j=i+1;j<m;j++){
                    if(graph[i][j] && graph[j][i] && !visit[j]){
                        visit[j]=1;
                        printf(", %s",name[j]);
                    }
                }
                printf("\n");
            }
        }

    }




    return 0;
}
