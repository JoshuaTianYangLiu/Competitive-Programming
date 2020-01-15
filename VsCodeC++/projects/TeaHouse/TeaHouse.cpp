#include <bits/stdc++.h>

using namespace std;
long long s1in[2010];
long long bit[100]
bool willOvercook(int a,int b,long long t){
    for(int i=a; i<=b; i++){
        if(s1in[i]<t)return true;
    }
    return false;
}
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    if(n<=2000&&q<=2000){
        for(int i=1; i<=n; i++)scanf("%lld",&s1in[i]);
        int a,b,c;
        long long d;
        while(q--){
            scanf("%d",&a);
            if(a==1){
                scanf("%d",&b);
                printf("%lld\n",s1in[b]);
                // for(int i=1; i<=n; i++){
                //     printf("%d ",s1in[i]);
                // }
                // printf("\n");
            }else if(a==2){
                scanf("%d %d %lld",&b,&c,&d);
                if(!willOvercook(b,c,d)){
                    for(int i=b; i<=c; i++)s1in[i]-=d;
                }
            }else if(a==3){
                scanf("%d %d %lld",&b,&c,&d);
                for(int i=b; i<=c; i++){
                    s1in[i]=d-c+i;
                }
            }else{
                scanf("%d %d",&b,&c);
                for(int i=b; i<=c; i++){
                    s1in[i]=floor(sqrt(s1in[i]));
                }
            }
        }
    }else{

    }
    return 0;
}