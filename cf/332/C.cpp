#include <bits/stdc++.h>

using namespace std;
pair<int,pair<int,int>> in[100010];
bool f(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    if(a.second.first==b.second.first) return a.first<b.first;
    return a.second.first>b.second.first;
}
bool f1(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.first>b.first;
}
int main() {
    int n,p,k;
    scanf("%d %d %d",&n,&p,&k);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        in[i]={b,{a,i+1}};
    }
    sort(in+p-k,in+n,f1);
    sort(in,in+n,f);
    // for(int i=0; i<p-k; i++){
    //     printf("%d ",in[i].second.second);
    // }
    // for(int i=0; i<n; i++){
    //     printf("%d ",in[i].second.second);
    // }
    // printf("\n");
    for(int i=0; i<p; i++){
        printf("%d ",in[i].second.second);
    }
    return 0;
}