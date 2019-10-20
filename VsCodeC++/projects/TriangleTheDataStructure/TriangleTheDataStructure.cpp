#include <bits/stdc++.h>

using namespace std;
int bit[3001][3001];
int in[3001][3001];
void insert(int x,int y1,int v){
    for(;x<3001;x+=x&-x){
        for(int y=y1;y<3001;y+=y&-y)bit[x][y]=max(bit[x][y],v);
    }
}
int query(int x,int y1){
    int n=0;
    for(;x;x-=x&-x){
        for(int y=y1;y;y-=y&-y)n=max(bit[x][y],n);
    }
    return n;
}
int main() {
    int size,t;
    scanf("%d %d",&size,&t);
    int ans=0;
    for(int i=1; i<=size; i++){
        for(int j=1; j<=i; j++){
            scanf("%d",&in[i][j]);
        }
    }
    for(int i=size; i>0; i--){
        for(int j=size,k=i; j>=i; j--){
            printf("%d %d %d %d %d\n",k,j,j,size-k+1,in[j][size-k+1]);
            insert(k,j,in[j][size-k+1]);k++;
        }
        for(int j=size,k=i; j>=i; j--){
            printf(" %d %d\n",k,j);
            if(size-k+1>=t){
                ans+=query(k+t-1,j);
            }
            k++;
        }
        printf("\n");
    }
    printf("%d",ans);
    return 0;
}
