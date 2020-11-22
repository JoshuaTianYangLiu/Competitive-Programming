#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int in[5010];
bool memo[5010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(memo,false,sizeof(memo));
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d",&in[i]);
        vector<pair<int,int>> edge;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(in[i]!=in[j]){
                    if(memo[i]&&memo[j])continue; 
                    memo[i]=true;
                    memo[j]=true;
                    edge.push_back({i,j});
                    // break;
                }
            }
        }
        // printf("::%d\n",edge.size());
        if(edge.size()==n-1){
            printf("YES\n");
            for(pair<int,int> a:edge)printf("%d %d\n",a.first+1,a.second+1);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}