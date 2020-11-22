#include <bits/stdc++.h>

using namespace std;
int in[24];
pair<int,pair,int,int>> memo[(1<<20)+10];
int memoize[memo[(1<<20)+10];
int mi(pair<int,pair<int,int>> a){return min(a.first,min(a.second.first,a.second.second));}
int dp(int mask){
    if(memoize[mask]!=-1)return mi(memo[mask]);
    
}
int main() {
    int n;
    memset(memoize,-1,sizeof(memoize));
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }

    //dp with bitmask
    return 0;
}