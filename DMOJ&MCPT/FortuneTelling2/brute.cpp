#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[200020];
int kin[200020];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        in[i]={a,b};
    }
    for(int i=0; i<k; i++){
        int a;
        scanf("%d",&a);
        kin[i]=a;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(in[i].first<=kin[j])swap(in[i].first,in[i].second);
        }
    }
    long long ans=0;
    for(int i=0; i<n; i++){
        int mi=min(in[i].first,in[i].second);
        int ma=max(in[i].first,in[i].second);
        printf("::%d %d %d\n",mi,ma,in[i].first);
        ans+=in[i].first;
    }
    printf("%lld\n",ans);
    return 0;
}