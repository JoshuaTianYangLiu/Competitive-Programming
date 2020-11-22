#include <bits/stdc++.h>

using namespace std;
map<int,int> bit[500010];
int in[500010];
void update(int x,int y1){
    for(;x<500010; x+=x&-x)
        for(int y=y1; y<500010; y+=y&-y)bit[x][y]++;
}
long long query(int x,int y1){
    long long ret=0;
    for(;x;x-=x&-x){
        for(int y=y1;y;y-=y&-y){
            if(bit[x].find(y)!=bit[x].end())
                ret+=bit[x][y];
        }
    }
    return ret;
}
long long query(int a,int b,int c,int d){
    return query(c,d)-query(a-1,d)-query(c,b-1)+query(a-1,b-1);
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    long long ans=0;
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        ans+=query(1,in[a]+1,a-1,500005);
        ans+=query(a+1,1,500005,in[a]-1);
        update(a,in[a]);
        printf("%lld\n",ans);
    }
    return 0;
}