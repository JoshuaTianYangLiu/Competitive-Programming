#include <bits/stdc++.h>

using namespace std;
int in[1000010];
int diff[1000010];
int f1(int a,int b){return a>b;}
int main() {
    int n,m,v;
    scanf("%d %d %d",&n,&m,&v);
    for(int i=1,a; i<=v; i++){
        scanf("%d",&a);
        in[i]=a;
    }
    sort(begin(in)+1,begin(in)+v+1);
    int ans=in[v]-in[1]+1;
    for(int i=1; i<v; i++){
        diff[i]=in[i+1]-in[i]-1;
    }
    sort(begin(diff)+1,begin(diff)+v,f1);
    // printf("%d\n",ans);
    for(int i=1; i<m; i++){
        ans-=diff[i];
    }
    printf("%d\n",ans);
    return 0;
}