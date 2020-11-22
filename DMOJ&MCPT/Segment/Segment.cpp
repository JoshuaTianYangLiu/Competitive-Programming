#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[1000001];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        in[i]={b,a};
    }
    sort(in,in+n);
    pair<int,int> ans={0,0};
    for(int i=0; i<n; i++){
        if(in[i].second>=ans.second)ans={ans.first+1,in[i].first};
    }
    printf("%d",ans.first);
    return 0;
}