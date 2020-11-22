#include <bits/stdc++.h>

using namespace std;
int in[1000010];

int dp[10010][1010];
vector<pair<int,int>> knap;
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    scanf("%d",&in[1]);
    int mi = in[1];
    for(int i=2; i<=n; i++){
        scanf("%d",&in[i]);
        if(in[i]<=mi){
            for(int j=mi; j<i; j++){
                
            }
        }
    }
    
    return 0;
}