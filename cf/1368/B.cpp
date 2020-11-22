#include <bits/stdc++.h>

using namespace std;
vector<int> pf(10,1);
long long pp(){
    long long ret=1;
    for(int i=0; i<10; i++){
        ret*=pf[i];
    }
    return ret;
}
int main() {
    long long k,kk;
    scanf("%lld",&k);kk=k;
    long long prod=1;
    while(pp()<k){
        for(int i=0; i<10; i++){
            if(pp()>=kk)break;
            pf[i]++;
        }
    }
    string a="codeforces";
    for(int i=0; i<10; i++){
        for(int j=0; j<pf[i]; j++)printf("%c",a[i]);
    }
    return 0;
}