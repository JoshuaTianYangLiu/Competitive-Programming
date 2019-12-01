#include <bits/stdc++.h>

using namespace std;
int in[100010];
struct
int tree[400040];
void build(int p,int l,int r){
    if(l==r)
}
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    build(1,1,n);
    return 0;
}
