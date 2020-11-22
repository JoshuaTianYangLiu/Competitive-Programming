#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int in[200010];
signed main() {
    int n,x;
    scanf("%d %d",&n,&x);
    for(int i=0; i<n; i++)scanf("%d",&in[i]);
    sort(in,in+n);
    int l=0,r=n-1;
    int ans=0;
    while(l<=r){
        // printf("%d %d\n",l,r);
        int cnt=in[r--];
        if(in[l]+cnt<=x)cnt+=in[l++];
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}