#include <bits/stdc++.h>

using namespace std;
int in[110];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(in,0,sizeof(in));
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            in[a]++;
        }
        int a=-1,b=-1;
        for(int i=0; i<=n; i++){
            if(a==-1&&in[i]<1)a=i;
            if(b==-1&&in[i]<2)b=i;
        }
        a=max(a,0);
        b=max(b,0);
        printf("%d\n",a+b);
    }
    return 0;
}