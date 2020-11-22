#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
char in[5010];
const int BB=131,MM=1e9+7;
ull ppow[5010];
ull hhash[5010];
int n;
unordered_set<ull> us;
ull q(int l,int r){
    return (hhash[r]-hhash[l])*ppow[n-l-1];
}
int main() {
    scanf("%s",in);
    n=strlen(in);
    ppow[0]=1;
    for(int i=1; i<=n; i++){
        ppow[i]=ppow[i-1]*BB;
    }
    for(int i=0; i<n; i++){
        hhash[i+1]=hhash[i]+(in[i]-'a'+1)*ppow[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j-i; k<=n; k+=j-i){
                if(us.count(q(i,j)))break;
                if(j+k>n)break;
                if(q(i,j)==q(i+k,j+k)){
                    ans++;
                    us.insert(q(i,j+k));
                }else{
                    break;
                }
                // printf("%d %d %d %d %d\n",i,i+k,i+2*k,j-k,j);
                // printf("%llu %llu %llu %llu %llu\n",q(i,i+k),q(j-k,j),q(i+k,i+2*k),q(i+k,j-k),q(i+2*k,j));
            }
        }
    }
    printf("%d\n",us.size());
    return 0;
}