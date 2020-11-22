#include <bits/stdc++.h>

using namespace std;
int in[150010];
int bit[300020];
void update(int n,int p){
    n+=150010;
    for(;n<300020;n+=n&-n)bit[n]+=p;
}
int query(int n){
    n+=150010;
    int sum=0;
    for(;n;n-=n&-n)sum+=bit[n];
    return sum;
}
int main() {
    int n;
    scanf("%d",&n);
    int ans=0;update(0,1);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        if(a==2)in[i]=-1;
        else in[i]=1;
        in[i]+=in[i-1];
        // printf("%d\n",in[i]);
        update(in[i],1);
        ans+=query(in[i]-1);
    }
    printf("%d",ans);

    return 0;
}