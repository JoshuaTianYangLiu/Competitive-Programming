#include <bits/stdc++.h>

using namespace std;
int in[100005];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
    }
    bool isNeg=true;
    long long ans=0;
    stack<int> s;
    for(int i=n; i>0; i--){
        if(in[i]<0&&isNeg){
            s.push(i);
            isNeg=false;
        }else if(in[i]>0&&!isNeg){
            s.push(i);
            isNeg=true;
        }
        ans+=abs(in[i]);
    }
    printf("%lld\n",ans);
    while(!s.empty()){
        printf("%d ",s.top());s.pop();
    }
    return 0;
}
