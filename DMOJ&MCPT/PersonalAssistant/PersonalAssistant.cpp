#include <bits/stdc++.h>

using namespace std;
struct event {long long a,b,c;} in[100001];
long long h[100001];
bool f(event n,event m){return n.b<m.b;}
bool f2(long long n,event m){return n<=m.b;}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%lld %lld %lld",&in[i].a,&in[i].b,&in[i].c);
        in[i].b+=in[i].a-1;
    }
    sort(in+1,in+n+1,f);
    h[0]=0;
    for(int i=1; i<=n; i++){
        int p = upper_bound(in,in+i,in[i].a,f2)-in-1;
        h[i]=max(h[i-1],in[i].c+h[p]);
    }
    printf("%lld",h[n]);
    return 0;
}
