#include <bits/stdc++.h>

using namespace std;
vector<int> primes;
bool p[10000010];
int pp[10000010];
map<int,int> q;
set<int> s;
int main() {
    for(int i=2; i<10000010; i++){
        if(!p[i]){
            primes.push_back(i);
            for(int j=i; j<10000010; j+=i)p[j]=true;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int a;
        scanf("%d",&a);
        int aa=a;
        for(int b:primes){
            if(aa==1)break;
            if(b*b>aa){
                pp[aa]++;
                // printf("::%d\n",aa);
                break;
            }
            if(aa%b==0){
                pp[b]++;
                // printf("%d %d\n",aa,b);
                aa/=b;
            }
        }
    }
    for(int i=2; i<10000010; i++)pp[i]+=pp[i-1];
    int m;
    scanf("%d",&m);
    for(int i=0,l,r; i<m; i++){
        scanf("%d %d",&l,&r);
        printf("%d\n",pp[r]-pp[l-1]);
    }
    return 0;
}