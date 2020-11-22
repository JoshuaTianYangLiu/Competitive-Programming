#include <bits/stdc++.h>

using namespace std;
int cnt(long long a){
    int ret=0;
    while(a){
        ret+=a%2;
        a/=2;
    }
    return ret;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,b;
        scanf("%lld %lld",&a,&b);
        if(b%a==0){
            if(cnt(b/a)==1){
                printf("%lld\n",((long long)log2(b/a)+2)/3);
            }else{
                printf("-1\n");
            }
        }else if(a%b==0){
            if(cnt(a/b)==1){
                printf("%lld\n",((long long)log2(a/b)+2)/3);
            }else{
                printf("-1\n");
            }
        }else{
            printf("-1\n");
        }
    }
    return 0;
}