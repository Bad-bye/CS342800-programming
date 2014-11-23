#include<stdio.h>



int solve(int x){
    int old,now,n,ans,i;
    for(ans=x+1,n=2*x;;ans++){
        old=0;
        for(i=0;i<=x-1;i++){
            now=(old+ans-1)%(n-i);
            old=now;
            if(now<x){
                break;
            }
        }
        if(i==x)
            return ans;
    }


}



int main(){
    int k,ans[14];
    int i,j;
    for(i=1;i<14;i++){
        ans[i]=solve(i);
    }
    while(scanf("%d",&k)!=EOF && k){
        printf("%d\n",ans[k]);


    }



    return 0;
}
