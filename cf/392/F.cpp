// Calculate all increasing possilities
/*
log2(1e7)==23.smt

Meaning mostly all cases its where the sequence is a times some integer

*/
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    if(n>24){
        printf("0\n");
        return 0;
    }
    if(n==1){
        printf("%d\n",r-l+1);
        return 0;
    }
    if(n==2){
        long long nn=r-l;
        printf("%lld\n",nn*(nn+1));
        return 0;
    }
    // Range of d is 2 to 2
    long long ans=0;
    for(int i=l; i<r; i++){
        for(int j=i+1; j<=r; j++){
            int common=__gcd(i,j);
            int a=i,b=j;
            a/=common;
            b/=common;
            bool pastR=false;
            bool cantDiv=false;
            long long t=j;
            for(int k=2; k<n; k++){
                if(t%a==0){
                    t/=a;
                    t*=b;
                    if(t>r){
                        pastR=true;
                        break;
                    }
                }else{
                    cantDiv=true;
                    break;
                }
            }
            // printf("%d %d %d %d\n",i,j,pastR,cantDiv);
            if(pastR)break;
            else if(!cantDiv)ans++;
        }
    }
    printf("%lld\n",2*ans);
    return 0;
}