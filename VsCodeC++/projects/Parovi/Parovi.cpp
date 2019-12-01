#include <bits/stdc++.h>

using namespace std;
pair<int,int> pairs[500];
int dp(int state,int cnt,int size,int n){
    printf("%d %d %d\n",__builtin_popcount(state),n,size-cnt+1);
    if(__builtin_popcount(state)==n)return size-cnt+1;
    int sum=;
    for(int i=cnt; i<=size; i++){
        int tmpState=state|(1<<(pairs[i].second-pairs[i].first)-1)<<pairs[i].first;
        sum+=dp(tmpState,i+1,size,n)%1000000000;
        sum%=1000000000;
    }
    return sum%1000000000;
}
int solve(int n){
    if(n==1)return 0;
    int cnt=1;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(__gcd(i,j)==1)pairs[cnt++]={i,j};
        }
    }
    return dp(0,1,cnt,n);
}
int main() {
    for(int i=1; i<=20; i++)printf("%d\n",solve(i));
    return 0;
}
