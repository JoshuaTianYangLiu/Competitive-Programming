#include <bits/stdc++.h>

using namespace std;
int in[300010];
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    for(int i=0,l,r; i<q; i++){
        scanf("%d %d",&l,&r);
        if(l>r){
            int buf=r;
            r=l;
            l=buf;
        }
        int ans=0;
        while(l<r){
            int a=INT_MAX,b=INT_MAX;
            if(l+1<=r)a=abs(in[l]-in[l+1]);
            if(l+2<=r)b=abs(in[l]-in[l+2]);
            if(a<b){
                ans+=a;
                l++;
            }else{
                ans+=b;
                l+=2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
