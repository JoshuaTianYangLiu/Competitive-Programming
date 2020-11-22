#include <bits/stdc++.h>

using namespace std;
int g[(1<<20)+2];
bool isRoot[(1<<20)+2];
int in[7][6];
int dirX[]={1,1,1,0,-1,-1,-1,0},dirY[]={1,0,-1,-1,-1,0,1,1};
int numOfNei(int n,int m){
    int num=0;
    for(int i=0; i<8; i++){
        if(in[n+dirX[i]][m+dirY[i]])num++;
    }
    return num;
}
void printInBin(int n){
    int cnt=20;
    while (cnt>-1) {

        if (n & (1<<cnt--))
            printf("1");
        else
            printf("0");

        
    }
}
int main() {
    memset(in,0,sizeof(in));
    memset(isRoot,true,sizeof(isRoot));
    int m,n,a,b,c;
    scanf("%d %d %d %d %d",&m,&n,&a,&b,&c);
    for(int i=0; i<(1<<m*n); i++){
        int t=m*n;
        for(int k=1; k<=m; k++){
            for(int j=1; j<=n; j++){
                in[j][k]=(i&(1<<--t))?1:0;
            }
        }
        int newGen=0;
        for(int k=1; k<=m; k++){
            for(int j=1; j<=n; j++){
                int num=numOfNei(j,k);
                newGen<<=1;
                if(in[j][k]){
                    if(num>=a&&num<=b)newGen++;
                }else{
                    if(num>c)newGen++;
                }
            }
        }
        // printInBin(i);
        // printf(" -> ");
        // printInBin(newGen);
        // printf("\n");
        g[i]=newGen;
        isRoot[newGen]=false;
    }
    int val=0;
    for(int k=1; k<=m; k++){
        for(int j=1; j<=n; j++){
            char in;
            scanf("%c",&in);
            while(in!='.'&&in!='*')scanf("%c",&in);
            val<<=1;
            val+=in=='*'?1:0;
        }
    }
    // printf("%d\n",val);
    int ans=INT_MAX;
    // while(1){
    //     int val2=0;
    //     for(int k=1; k<=m; k++){
    //         for(int j=1; j<=n; j++){
    //             char in;
    //             scanf("%c",&in);
    //             while(in!='.'&&in!='*')scanf("%c",&in);
    //             val2<<=1;
    //             val2+=in=='*'?1:0;
    //         }
    //     }
    //     printInBin(val2);
    //     printf(" -> ");
    //     printInBin(g[val2]);
    //     printf("\n");
    // }
    for(int i=0,j; i<=(1<<m*n); i++){
        if(isRoot[i]){
            j=i;
            for(int k=0; k<=50; k++){
                if(j==val){
                    ans=min(ans,k);
                    break;
                }
                j=g[j];
            }
        }
    }
    if(ans!=INT_MAX)printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
