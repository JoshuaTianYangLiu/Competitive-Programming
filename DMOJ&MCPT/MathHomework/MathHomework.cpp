#include <bits/stdc++.h>

using namespace std;
const int MM=1e9+7;
long long ppow[3010];
long long memo[3010];
long long fac[6020];
int pascal[3010][3010];
long long fpow(long long x, long long y) {
  return !y?1:((y % 2 ? x : 1) * fpow((x * x) % MM, y / 2)) % MM;
}
long long choose(int n,int k){
    return pascal[n][k];
}
int main() {
    int t;
    scanf("%d",&t);
    ppow[0]=1;
    for(int i=1; i<3010; i++){
        ppow[i]=(ppow[i-1]*2)%MM;
    }
    fac[0]=1;
    for(int i=1; i<6020; i++){
        fac[i]=(fac[i-1]*i)%MM;
    }
    for(int i=0; i<3010; i++){
        for(int j=0;j<=i; j++){
            if(i==0||j==0)pascal[i][j]=1;
            else pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%MM;
        }
    }
    while(t--){
        int r,c;
        scanf("%d %d",&r,&c);
        for(int i=1; i<=c; i++){
            memo[i]=fpow(ppow[i]-1,r);
            for(int j=1; j<i; j++){
                memo[i]-=(choose(i,j)*memo[j])%MM;
                memo[i]=(memo[i]+MM)%MM;
            }
        }
        printf("%d\n",memo[c]);
    }
    return 0;
}