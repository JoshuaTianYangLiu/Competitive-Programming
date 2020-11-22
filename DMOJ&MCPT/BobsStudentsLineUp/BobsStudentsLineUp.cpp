#include <bits/stdc++.h>

using namespace std;
char in[300010];
int sumLeft[300010],sumRight[300010];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",in+1);
    for(int i=1; i<=n; i++){
        if(in[i]=='L'){
            sumLeft[i]=1;
        }
        sumLeft[i]+=sumLeft[i-1];
    }
    for(int i=n; i>0; i--){
        if(in[i]=='R'){
            sumRight[i]=1;
        }
        sumRight[i]+=sumRight[i+1];
    }
    int ans=1e9;
    for(int i=1; i<=n; i++){
        ans=min(ans,sumLeft[i-1]+sumRight[i+1]);
    }
    printf("%d\n",ans);
    return 0;
}