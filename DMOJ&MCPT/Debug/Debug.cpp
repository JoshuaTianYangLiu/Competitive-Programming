#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull ppow[310];
ull hhash[310][310];
ull revHhash[310][310]; 
char in[310][310];
int BB=131;
int n,m;
ull q(int x,int l,int r){
    return (hhash[x][r]-hhash[x][l-1])*ppow[m-l];
}
ull qr(int x,int l,int r){
    return (revHhash[x][l]-revHhash[x][r+1])*ppow[r-1];
}
bool cnt(int i,int j,int k){
    if(i<1||j<1)return false;
    if(i+k-1>n||j+k-1>m)return false;
    // printf("%d %d %d\n",i,j,k);
    for(int l=0; l<(k+1)/2; l++){
        // printf("1:: %d %d %d %llu\n2:: %d %d %d %llu\n",i+k-l-1,j,j+k-1,qr(i+k-l-1,j,j+k-1),i+l,j,j+k-1,q(i+l,j,j+k-1));
        if(qr(i+k-l-1,j,j+k-1)!=q(i+l,j,j+k-1))return false;
    }
    return true;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%s",in[i]);
    }
    ppow[0]=BB;
    for(int i=1; i<=m; i++){
        ppow[i]=ppow[i-1]*BB;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            hhash[i+1][j+1]=hhash[i+1][j]+(in[i][j]-'0'+3)*ppow[j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            revHhash[i+1][m-j]=revHhash[i+1][m-j+1]+(in[i][m-j-1]-'0'+3)*ppow[j];
        }
    }
    int ans=-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=0; k<2; k++){
                int a=k;
                while(cnt(i-a/2,j-a/2,a))a+=2;
                ans=max(ans,a-2);
            }
        }
    }
    if(ans>1) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}