#include <bits/stdc++.h>

using namespace std;
int k,n;
int in[1000010];
vector<int> psa[1000010];
vector<int> pp[1000010];
double memo[1000010];
int last[1000010];
int freq(int m,int l,int r){
    int lb=lower_bound(psa[m].begin(),psa[m].end(),l)-psa[m].begin();
    int ub=upper_bound(psa[m].begin(),psa[m].end(),r)-psa[m].begin();
    return ub-lb;
}
int main() {
    // freopen("5a.in","r",stdin);
    scanf("%d %d",&k,&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&in[i]);
        psa[in[i]].push_back(i);
        if(in[i]!=in[i-1])pp[in[i]].push_back(i);
        last[i]=1;
    }
    double ans=0;
    // You can also discard cards :> im baf
    for(int i=1; i<=n; i++){
        // printf("%d\n",i);
        // for(int j:pp[in[i]]){
        for(int j=last[in[i]]; j<=i; j++){
            // if(j>i)break;
            if(in[i]==in[j]){
                // printf("::%2lf\n",memo[j-1]+pow(freq(in[i],j,i),k/2.0));
                double a=memo[j-1]+pow(freq(in[i],j,i),k/2.0);
                if(a>memo[i]){
                    memo[i]=a;
                    last[in[i]]=j;
                }
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     printf("%.2lf\n",memo[i]);
    // }
    printf("%.9lf\n",memo[n]);

    return 0;
}