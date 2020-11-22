#include <bits/stdc++.h>

using namespace std;
vector<int> g[100010];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0,a,b; i<m; i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    return 0;
}