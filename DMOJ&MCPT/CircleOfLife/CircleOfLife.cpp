#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char in[100010],in2[100010];
int n;ll t;
int m(int a,int n){
    return a<0?a%n+n:a%n;
}
int main(){
    scanf("%d %lld",&n,&t);
    scanf("%s",in);
    for(int i=0; i<n; i++)in[i]-='0';
    for(int i=0; i<63; i++){
        if((t>>i)&1){
            int k=(1ll<<i)%n;
            // printf("%d ",k);
            for(int j=0; j<n; j++)in2[j]=in[m(j-k,n)]^in[m(j+k,n)];
            for(int j=0; j<n; j++)in[j]=in2[j];
        }
    }
    for(int i=0; i<n; i++)printf("%d",in[i]);
    return 0;
}