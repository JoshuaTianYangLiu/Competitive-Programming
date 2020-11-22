#include <bits/stdc++.h>

using namespace std;
int n,m,q;
int diff[25000010];
int solve(int a){
    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int b=m*n-a+1;
            if(a>=i*j&&b>=(n-i+1)*(m-j+1))ans++;
        }
    }
    return ans;
}


int main() {
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int a = i*j;
            int b =(n-i+1)*(m-j+1);
            b=m*n-b+1;
            diff[a]++;
            diff[b+1]--;
            // printf("%d %d\n",a,b);
        }
    }
    for(int i=1; i<=m*n; i++)diff[i]+=diff[i-1];
    while(q--){
        int a;
        scanf("%d",&a);
        printf("%d\n",diff[a]);
    }
    return 0;
}