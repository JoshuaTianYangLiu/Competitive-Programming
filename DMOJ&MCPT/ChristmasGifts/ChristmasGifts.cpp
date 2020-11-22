#include <bits/stdc++.h>

using namespace std;
pair<int,int> in[1010];
int a[1010];
bool f1(pair<int,int> a,pair<int,int> b){
    if(a.first+a.second==b.first+b.second) return a<b;
    return a.first+a.second<b.first+b.second;
}
int sum(pair<int,int> a){return a.first+a.second;}
int main() {
    int n,b;
    scanf("%d %d",&n,&b);
    for(int i=1,q,p; i<=n; i++){
        scanf("%d %d",&q,&p);
        in[i]={q,p};
    }
    sort(begin(in)+1,begin(in)+n+1,f1);
    
    for(int i=1; i<=n; i++){
        if(sum(in[i])>b){
            if(in[i].first/2+in[i].second>b){
                printf("%d\n",i-1);
            }else{
                printf("%d\n",i);
            }
            return 0;
        }else{
            b-=sum(in[i]);
        }
    }
    printf("%d\n",n);
    return 0;
}