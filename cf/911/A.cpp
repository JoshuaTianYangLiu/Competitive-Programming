#include <bits/stdc++.h>

using namespace std;
int in[100010];
int main() {
    int n;
    scanf("%d",&n); 
    int mm=2e9;
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
        mm=min(mm,in[i]);
    }
    int pos=-1,ans=1e9;
    for(int i=1; i<=n; i++){
        if(in[i]==mm){
            if(pos!=-1)ans=min(ans,i-pos);
            pos=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}