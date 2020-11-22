#include <bits/stdc++.h>

using namespace std;
char in[1000010];
int ans[1000010];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",in);
    int hi=-1;
    for(int i=0; i<n; i++){
        if(in[i]=='1')hi=i;
        else{
            if(hi!=-1)ans[i]=hi;
            else ans[i]=-1e9;
        }
    }
    hi=-1;
    for(int i=n-1; i>=0; i--){
        if(in[i]=='1')hi=i;
        else{
            if(hi!=-1)ans[i]=i-ans[i]<hi-i?ans[i]:hi;
        }
    }
    long long ans1=0;
    for(int i=0; i<n; i++)if(in[i]=='0')ans1+=abs(i-ans[i]);
    printf("%lld\n",ans1);
    return 0;
}