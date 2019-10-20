#include <bits/stdc++.h>

using namespace std;
bool arr[1000010];
int f(int n,long long m){
    memset(arr,0,sizeof(arr));
    // int n;
    // long long m;
    // scanf("%d %lld",&n,&m);
    //some sort of modified sieve
    int ans=0,ans1=0;
    for(int i=2; i<=n; i++){
        ans1=0;
        for(int j=1; j*i<=m; j++){
            if(!arr[j*i]){
                ans++;
                arr[j*i]=true;
            }else{
                ans1++;
            }
        }
        printf("%d ",ans1);
    }
    // printf("%d",ans);
    return ans;
}
int main() {
    for(int i=0; i<=200; i++){
        printf("%d :",i);
            f(20,i);
            // printf("%d ",f(j,i));
        printf("\n");
    }
}