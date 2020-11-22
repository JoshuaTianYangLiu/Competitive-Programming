#include <bits/stdc++.h>

using namespace std;
long long in[100010];
int n,q;
int why(long long c){
    for(int i=1; i<=n; i++){
        if(in[i]>=c)return i;
    }
    return -1;
}
int main() {
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++)scanf("%lld",&in[i]);
    for(int i=1,a; i<=n; i++){
        scanf("%d",&a);
        in[i]+=in[a];
    }
    for(int i=1; i<=n; i++)in[i]=max(in[i],in[i-1]);
    long long b,c;
    // for(int i=1; i<=n; i++){
    //     printf("%lld ",in[i]);
    // }
    while(q--){
        scanf("%lld %lld",&b,&c);
        c-=b;
        if(c<=0){
            printf("-1\n");
            continue;
        }
        printf("%d\n",why(c));
        // int yes = (int)(upper_bound(begin(in)+1,begin(in)+1+n,c-1)-begin(in));
        // if(yes==-1||yes>n)printf("-1\n");
        // else printf("%d\n",yes);
    }
    return 0;
}