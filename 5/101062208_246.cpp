#include<stdio.h>
#include<stdlib.h>

int hand[52],handnum;
int pile[7][52],pilenum[7];
int save[8][52],savenum[8],first[8][52],firstnum[8];
int count,tempcount,f;


void play(int i){
    int j;
    count++;
    pile[i][pilenum[i]]=hand[0];
    handnum--;
    pilenum[i]++;
    for(j=0;j<handnum;j++){
        hand[j]=hand[j+1];
    }
    while(pilenum[i]>=3){
        if((pile[i][0]+pile[i][1]+pile[i][pilenum[i]-1])%10==0){
            hand[handnum++]=pile[i][0];
            hand[handnum++]=pile[i][1];
            hand[handnum++]=pile[i][pilenum[i]-1];
            pilenum[i]-=3;
            for(j=0;j<pilenum[i];j++){
                pile[i][j]=pile[i][j+2];
            }
        }
        else if((pile[i][0]+pile[i][pilenum[i]-2]+pile[i][pilenum[i]-1])%10==0){
            hand[handnum++]=pile[i][0];
            hand[handnum++]=pile[i][pilenum[i]-2];
            hand[handnum++]=pile[i][pilenum[i]-1];
            pilenum[i]-=3;
            for(j=0;j<pilenum[i];j++){
                pile[i][j]=pile[i][j+1];
            }
        }
        else if((pile[i][pilenum[i]-3]+pile[i][pilenum[i]-2]+pile[i][pilenum[i]-1])%10==0){
            hand[handnum++]=pile[i][pilenum[i]-3];
            hand[handnum++]=pile[i][pilenum[i]-2];
            hand[handnum++]=pile[i][pilenum[i]-1];
            pilenum[i]-=3;
        }
        else
            break;
    }
}
void play2(int i){
    int j;
    first[i][firstnum[i]]=first[7][0];
    firstnum[7]--;
    firstnum[i]++;
    for(j=0;j<firstnum[7];j++){
        first[7][j]=first[7][j+1];
    }
    while(firstnum[i]>=3){
        if((first[i][0]+first[i][1]+first[i][firstnum[i]-1])%10==0){
            first[7][firstnum[7]++]=first[i][0];
            first[7][firstnum[7]++]=first[i][1];
            first[7][firstnum[7]++]=first[i][firstnum[i]-1];
            firstnum[i]-=3;
            for(j=0;j<firstnum[i];j++){
                first[i][j]=first[i][j+2];
            }
        }
        else if((first[i][0]+first[i][firstnum[i]-2]+first[i][firstnum[i]-1])%10==0){
            first[7][firstnum[7]++]=first[i][0];
            first[7][firstnum[7]++]=first[i][firstnum[i]-2];
            first[7][firstnum[7]++]=first[i][firstnum[i]-1];
            firstnum[i]-=3;
            for(j=0;j<firstnum[i];j++){
                first[i][j]=first[i][j+1];
            }
        }
        else if((first[i][firstnum[i]-3]+first[i][firstnum[i]-2]+first[i][firstnum[i]-1])%10==0){
            first[7][firstnum[7]++]=first[i][firstnum[i]-3];
            first[7][firstnum[7]++]=first[i][firstnum[i]-2];
            first[7][firstnum[7]++]=first[i][firstnum[i]-1];
            firstnum[i]-=3;
        }
        else
            break;
    }
}

int isdraw(void){
    int i,j;
    if(savenum[7]!=handnum)
        return 0;
    for(i=0;i<handnum;i++){
        if(save[7][i]!=hand[i])
            return 0;
    }
    for(i=0;i<7;i++){
        if(savenum[i]!=pilenum[i])
            return 0;
        for(j=0;j<pilenum[i];j++){
            if(save[i][j]!=pile[i][j])
                return 0;
        }
    }
    return 1;
}

int isdraw2(void){
    int i,j;
    if(firstnum[7]!=handnum)
        return 0;
    for(i=0;i<handnum;i++){
        if(first[7][i]!=hand[i])
            return 0;
    }
    for(i=0;i<7;i++){
        if(firstnum[i]!=pilenum[i])
            return 0;
        for(j=0;j<firstnum[i];j++){
            if(first[i][j]!=pile[i][j])
                return 0;
        }
    }
    return 1;
}

int find(void){
    int i,j,k;
    for(i=0;i<52;i++)
        hand[i]=0;
    for(i=0;i<7;i++){
        for(j=0;j<52;j++)
            pile[i][j]=0;
    }
    for(i=0;i<7;i++){
        pilenum[i]=2;
        firstnum[i]=2;
    }
    firstnum[7]=38;
    handnum=38;
    for(i=0;i<7;i++){
        pile[i][0]=first[i][0];
        pile[i][1]=first[i][1];
    }
    for(i=0;i<38;i++)
        hand[i]=first[7][i];
    count=14;
    for(i=0,j=1;j<=f;j++){
        if(i==7)
            i=0;
        if(pilenum[i]==0){
            i++;
            if(i==7)
                i=0;
        }
        play(i++);
    }
    for(j=0;;i++,j++){
        if(i==7)
            i=0;
        if(j==7)
            j=0;
        while(pilenum[i]==0){
            i++;
            if(i==7)
                i=0;
        }
        while(firstnum[j]==0){
            j++;
            if(j==7)
                j=0;
        }
        play(i);
        play2(j);
        if(isdraw2()){
            return count;
        }
    }


}


int main(){
    freopen("246.in","r",stdin);
    int i,j,k;
    while(1){
        for(i=0;i<52;i++)
            hand[i]=0;
        for(i=0;i<7;i++){
            for(j=0;j<52;j++){
                pile[i][j]=0;
                first[i][j]=0;
            }
        }
        scanf("%d",&pile[0][0]);
        if(pile[0][0]==0)
            break;
        first[0][0]=pile[0][0];
        for(i=1;i<7;i++){
            scanf("%d",&pile[i][0]);
            first[i][0]=pile[i][0];
        }
        for(i=0;i<7;i++){
            scanf("%d",&pile[i][1]);
            first[i][1]=pile[i][1];
        }
        for(i=0;i<38;i++){
            scanf("%d",&hand[i]);
            first[7][i]=hand[i];
        }
        handnum=38;
        for(i=0;i<7;i++){
            pilenum[i]=2;
            firstnum[i]=2;
        }
        firstnum[7]=38;
        count=14;
        for(i=0;;i++){
            if(i==7)
                i=0;
            if(pilenum[i]==0)
                continue;
            play(i);

            if(handnum==52){
                printf("Win : %d\n",count);
                break;
            }
            else if(handnum==0){
                printf("Loss: %d\n",count);
                break;
            }
            else if(isdraw()){
                f=count-tempcount;
                printf("Draw: %d\n",find());
                break;
            }

            if(count==16 || count==32 || count==64 ||count==128 ||count==256 || count==512 || count==1024){
                for(j=0;j<7;j++){
                    savenum[j]=pilenum[j];
                    for(k=0;k<52;k++){
                        save[j][k]=pile[j][k];
                    }
                }
                tempcount=count;
                savenum[7]=handnum;
                for(j=0;j<52;j++)
                    save[7][j]=hand[j];
            }
        }


    }



    return 0;
}
