#include <bits/stdc++.h>

using namespace std;
int in[110];
int locked[110];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&in[i]);
        for(int i=1; i<=n; i++)scanf("%d",&locked[i]);
        vector<int> aa;
        for(int i=1; i<=n; i++){
            if(locked[i]==0)aa.push_back(in[i]);
        }
        sort(aa.rbegin(),aa.rend());
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(locked[i])printf("%d ",in[i]);
            else printf("%d ",aa[cnt++]);
        }
        printf("\n");
    }
    return 0;
}