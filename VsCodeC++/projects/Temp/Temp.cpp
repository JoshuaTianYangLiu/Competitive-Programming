#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[3000030];
int main() {
    long long n,m;
    scanf("%lld %lld",&n,&m);
    long long a=0,b=0;
    for(int i=0; i<n; i++){
        scanf("%d %d",&in[i].first,&in[i].second);
        a+=in[i].first-1;
        b+=in[i].second-1;
    }
    a=max(a,(m-1)*n-a);b=max(b,(m-1)*n-b);
    printf("%lld\n",a+b);
    return 0;
}