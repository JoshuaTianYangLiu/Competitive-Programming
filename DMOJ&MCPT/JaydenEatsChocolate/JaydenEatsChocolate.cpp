#include <bits/stdc++.h>

using namespace std;
int arr[3],memo[100010];
int n;
int dp(){
    for(int i=1; i<=n; i++){
        for(int j:arr){
            if(i-j>=0&&memo[i-j]!=-1){
                memo[i]=max(memo[i],memo[i-j]+1);
            }
        }
    }
    return memo[n];
}
int main() {
    memset(memo,-1,sizeof(memo));memo[0]=0;
    scanf("%d %d %d %d",&n,&arr[0],&arr[1],&arr[2]);
    printf("%d\n",dp());
    return 0;
}
