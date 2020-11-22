#include <bits/stdc++.h>

using namespace std;
double in[3010];
double memo[3010][3010];
int n;
double f(int idx,int heads){
    if(heads>n-idx+1)return 0;
    if(idx>n)return 1;
    if(memo[idx][heads]!=-1)return memo[idx][heads];
    if(heads==0)return memo[idx][heads]=f(idx+1,heads)*(1-in[idx]);
    return memo[idx][heads]=f(idx+1,heads)*(1-in[idx])+f(idx+1,heads-1)*in[idx];
}
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%lf",&in[i]);
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            memo[i][j]=-1;
        }
    }
    double ans=0;
    for(int i=(n+1)/2; i<=n; i++){
        ans+=f(1,i);
    }
    printf("%.10lf",ans);
    return 0;
}