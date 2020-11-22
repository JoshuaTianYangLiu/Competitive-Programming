#include <bits/stdc++.h>

using namespace std;
int diff[10010];
set<pair<int,int>> ty;
int main() {
    int N,I,H,M,i,j;
    scanf("%d %d %d %d",&N,&I,&H,&M);
    diff[0]=H;
    while(M--){
        scanf("%d %d",&i,&j);
        if(ty.find({i,j})==ty.end()){
            ty.insert({i,j});
            diff[min(i,j)+1]--;
            diff[max(i,j)]++;
        }
    }
    
    for(int i=1; i<=N; i++){
        diff[i]+=diff[i-1];
        printf("%d\n",diff[i]);
    }
    return 0;
}