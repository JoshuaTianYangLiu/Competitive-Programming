#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int in[200010],apart[200010];
int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<n; i++)scanf("%d",&in[i]);
    for(int i=0; i<m; i++)scanf("%d",&apart[i]);
    sort(in,in+n);
    sort(apart,apart+m);
    int cnt=0;
    int ans=0;
    for(int i=0; i<n; i++){
        if(cnt>=n)break;
        while(apart[cnt]<in[i]-k)cnt++;
        if(cnt>=n)break;
        if(in[i]-k<=apart[cnt]&&apart[cnt]<=in[i]+k){
            // printf("%d %d\n",in[i],apart[i]);
            ans++;
            cnt++;
        }
    }
    printf("%d\n",ans);
    return 0;
}