#include <bits/stdc++.h>

using namespace std;
int in[100001];
vector<int> in2;
int f[100001];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
        in2.push_back(in[i]);
    }
    for(int i=0,a,b; i<m; i++){
        scanf("%d %d",&a,&b);
        if(in[--a]>in[--b])f[a]++;
        else if(in[a]<in[b])f[b]++;
    }
    sort(in2.begin(),in2.end());
    for(int i=0; i<n; i++){
        int o=upper_bound(in2.begin(),in2.end(),in[i]-1)-in2.begin();
        printf("%d ",o-f[i]);
    }
    return 0;
}
