#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool prime[100010];
vector<int> pf[100010];
int facCnt[100010];
int brute(int a,int b,int c){
    set<pair<int,pair<int,int>>> s;
    for(int i=1; i<=a; i++){
        if(a%i==0){
            for(int j=1; j<=b; j++){
                if(b%j==0){
                    for(int k=1; k<=c; k++){
                        if(c%k==0){
                            int ree[]={i,j,k};
                            sort(ree,ree+3);
                            s.insert({ree[0],{ree[1],ree[2]}});
                        }
                    }
                }
            }
        }
    }
    return s.size();
}
int gfac(int n){
    if(facCnt[n])return facCnt[n];
    int nn=n;
    int ret=1;
    int sz=pf[n].size();
    int cnt=0;
    for(int i=0; i<sz; i++){
        while(n%pf[nn][i]==0){
            cnt++;
            n/=pf[nn][i];
        }
        ret*=cnt+1;
        cnt=0;
    }
    return facCnt[nn]=ret;
}
int gcd(int a,int b){return a%b?gcd(b,a%b):b;}
int main() {
    for(int i=2; i<=100010; i++){
        if(!prime[i]){
            for(int j=i; j<100010; j+=i){
                pf[j].push_back(i);
                prime[j]=true;
            }
        }
    }
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        ll ans=gfac(a)*gfac(b)*gfac(c);
        // ans-=gfac(gcd(a,b));
        ans-=gfac(gcd(a,b))*gfac(gcd(a,b))+
        gfac(gcd(b,c))*gfac(gcd(b,c))+
        gfac(gcd(a,c))*gfac(gcd(a,c));
        // ans+=gfac(gcd(gcd(a,b),c));
        printf("%d %lld\n",brute(a,b,c),ans);
    }
    return 0;
}