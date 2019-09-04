#include <bits/stdc++.h>

using namespace std;
struct t {int a,b,c;} in[50001];
bool f(t n,t m){return n.a>m.a;}
bool f2(t n,t m){return n.b>m.b;}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%d %d",&in[i].a,&in[i].b);
        in[i].c=i+1;
    }
    sort(in,in+n,f);
    sort(in,in+m,f2);
    printf("%d\n",in[0].c);
    return 0;
}