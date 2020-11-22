#include <bits/stdc++.h>

using namespace std;
int sieve[200020];
int main() {
    for(int i=2; i<200020; i++){
        if(sieve[i]==0)
            for(int j=i; j<200020; j+=i)sieve[j]=i;
    }
    int n;
    scanf("%d",&n);
    int ans=0;
    while(n--){
        int a;
        scanf("%d",&a);
        if(sieve[a]>sieve[ans]) ans=a;
    }
    printf("%d\n",ans);
    return 0;
}