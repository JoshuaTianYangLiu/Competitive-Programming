#include <bits/stdc++.h>

using namespace std;
char in[200010];
int n;
int solve(int a,int b){
    int cnt=0;
    if(a==b){
        for(int i=0; i<n; i++){
            char c=in[i];
            if(c-'0'==a){
                cnt++;
            }
        }
    }else{
        for(int i=0; i<n; i++){
            char c=in[i];
            // printf("%d ",c-'0');
            if(cnt%2==0&&c-'0'==a){
                cnt++;
            }else if(cnt%2==1&&c-'0'==b){
                cnt++;
            }
        }
        // printf("\n");
        cnt/=2;
        cnt*=2;
    }
    return cnt;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        n=strlen(in);
        int ans=0;
        for(int i=0; i<=9; i++){
            for(int j=0; j<=9; j++){
                int ree=solve(i,j);
                if(ree>ans){
                    // printf("%d %d %d\n",i,j,ree);
                    ans=max(ans,ree);
                }
            }
        }
        printf("%d\n",strlen(in)-ans);
    }
    return 0;
}