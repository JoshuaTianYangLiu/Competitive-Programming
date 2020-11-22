/*
We can apply the matrix algo
--     --   --    --   --    --
| a b c |   | Fn   |   | Fn+1 |
| 1 0 0 | X | Fn-1 | = | Fn   |
| 0 1 0 |   | Fn-2 |   | Fn-1 |
--     --   --    --   --    --
*/
#include <bits/stdc++.h>

using namespace std;
const int MM=1e9+7;
typedef long long ll;
typedef vector<vector<ll>> Mat;
char in[10010];
int n;
int a[15];
Mat initMatrix(){
    Mat ret(n);
    for(int i=0; i<n; i++){ret[0].push_back(a[i]);}
    for(int i=1; i<n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)ret[i].push_back(1);
            else ret[i].push_back(0);
        }
    }
    return ret;
}
Mat initIdentity(){
    Mat ret(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)ret[i].push_back(1);
            else ret[i].push_back(0);
        }
    }
    return ret;
}
Mat mul(Mat a, Mat b){
    Mat ret(n);
    for(int i=0; i<n; i++){
        ret[i].resize(n);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%MM;
            }
        }
    }
    return ret;
}
void print(Mat a){
    for(int i=0; i<n; i++){
        long long hihi=0;
        for(int j=0; j<n; j++){
            printf("%lld ",a[i][j]);
            hihi+=a[i][j];
            hihi%=MM;
        }
        printf("%lld",hihi);
        printf("\n");
    }
}
int len;
void minusOne(){
    for(int i=len-1; i>=0; i--){
        if(in[i]!='0'){
            in[i]--;
            break;
        }else{
            in[i]='9';
        }
    }
}
Mat cachedI;
int main() {
    scanf("%d %s",&n,in);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    cachedI=initIdentity();
    Mat ans = initMatrix();
    Mat I = cachedI;
    Mat finalAns=cachedI;
    len = strlen(in);
    minusOne();
    for(int i=len-1; i>=0; i--){
        for(int j=0; j<in[i]-'0'; j++){
            finalAns=mul(finalAns,ans);
        }
        Mat II = cachedI;
        for(int j=0; j<10; j++)II=mul(II,ans);
        ans=II;
    }
    ll finalfinalAns=0;
    for(int i=0; i<n; i++){
        finalfinalAns+=finalAns[n-1][i];
        finalfinalAns%=MM;
    }
    printf("%lld\n",finalfinalAns);
    // print(finalAns);
    return 0;
}