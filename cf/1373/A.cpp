#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,b,c;
        long long ree=1e9;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a<c){
            printf("1 ");
        }else if(a*ree<c*ceil(ree*1.0/b)){
            printf("%d ",ree);
        }else{
            printf("-1 ");
        }
        if(a>c){
            printf("1\n");
        }else if(a*ree>c*ceil(ree*1.0/b)){
            printf("%d\n",ree);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}