#include <bits/stdc++.h>

using namespace std;
int in[1510];
int bit[1510];
void update(int x){
    for(;x<1510; x+=x&-x)bit[x]++;
}
int query(int x){
    int ret=0;
    for(;x;x-=x&-x)ret+=bit[x];
    return ret;
}
int main() {
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
        ans+=query(1501)-query(in[i]-1);
        update(in[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        int n=b-a+1;
        ans=abs(ans-n*(n-1)/2);
        printf("%s\n",ans%2==0?"even":"odd");
    }

    return 0;
}