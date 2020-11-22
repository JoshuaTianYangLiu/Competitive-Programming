#include <bits/stdc++.h>

using namespace std;
bool brute(int n){
    if(n%2==0)return false;
    int div=0;
    for(int i=1; i<=n; i++){
        if(n%i==0)div++;
    }
    return div%2==0;
}
int check(int n){
    int ans=0;
    for(int i=1; i<=n; i++){
        if(brute(i))ans++;
    }
    return ans;
}
int main() {
    int n;
    scanf("%d",&n);
    int ans=(n+1)/2;
    for(int i=1; i<=n; i+=2){
        if(i*i<=n)ans--;
        else break;
    }
    printf("%d\n",ans);
    
    return 0;
}