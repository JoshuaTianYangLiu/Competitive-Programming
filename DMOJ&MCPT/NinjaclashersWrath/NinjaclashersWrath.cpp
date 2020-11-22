#include <bits/stdc++.h>

using namespace std;
int h[100010],d[100010];
int n;
pair<int,int> search(int m){
    pair<int,int> ret;
    double slope=-2000000000.0;
    int ans=-1;
    for(int i=m-1; i>0; i--){
        double t = (h[i]-h[m])/(double)(d[m]-d[i]);
        if(t>=slope){
            ans=max(ans,h[i]);
            slope=t;
        }
    }
    ret.first=ans;
    slope=-2000000000.0;
    ans=-1;
    for(int i=m+1; i<=n; i++){
        double t = (h[i]-h[m])/(double)(d[i]-d[m]);
        if(t>=slope){
            ans=max(ans,h[i]);
            slope=t;
        }
        // printf("::%d %.3f\n",h[i],t);
    }
    ret.second=ans;
    if(m==1)ret.first=-1;
    if(m==n)ret.second=-1;
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&h[i]);
    }
    for(int i=2; i<=n; i++){
        scanf("%d",&d[i]);
        d[i]+=d[i-1];
    }
    for(int i=1; i<=n; i++){
        pair<int,int> t = search(i);
        printf("%d %d\n",t.first,t.second);
    }
    return 0;
}