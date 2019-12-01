#include <bits/stdc++.h>

using namespace std;
int diffArr[100010];
long long in[100010];
bool cmp(int a,int b){return a>b;}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0; i<n; i++){
        scanf("%d",&in[i]);
    }
    for(int i=0,a,b; i<q; i++){
        scanf("%d %d",&a,&b);
        diffArr[a-1]++;
        diffArr[b]--;
    }
    for(int i=1; i<n; i++){
        diffArr[i]+=diffArr[i-1];
    }
    sort(begin(diffArr),begin(diffArr)+n);
    sort(begin(in),begin(in)+n,cmp);
    long long ans=0;
    for(int i=0; i<n; i++){
        ans+=in[i]*diffArr[i];
    }
    printf("%lld",ans);
    return 0;
}