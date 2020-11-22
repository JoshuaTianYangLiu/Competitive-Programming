#include <bits/stdc++.h>

using namespace std;
pair<int,pair<int,int>> range[300030];
void updateRange(int x,int l,int r){
    for(;x<300030; x+=x&-x){
        range[x].first+=l;
        range[x].second.first+=r;
    }
}
void updateEverything(int x,int l,int r,int p){
    for(;x<300030; x+=x&-x){
        range[x].first+=l;
        range[x].second.first+=r;
        range[x].second.second+=p;
    }
}
void updateRangeEverything(int l,int r,int u,int v,int p){
    updateEverything(l,u,v,p);
    updateEverything(r+1,-u,-v,-p);
}
void updateRange(int l,int r,int u,int v){
    updateRange(l,u,v);
    updateRange(r+1,-u,-v);
}
pair<int,pair<int,int>> queryEverything(int x){
    pair<int,pair<int,int>> ret={0,{0,0}};
    for(;x;x-=x&-x){
        ret.first+=range[x].first;
        ret.second.first+=range[x].second.first;
        ret.second.second+=range[x].second.second;
    }
    return ret;
}

int depth[300030];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    pair<int,int> r;
    pair<int,pair<int,int>> pp;
    int par;
    long long finalAns=0;
    // scanf("%d",&n);
    cin>>n;
    updateRange(1,300000,1,300000);
    for(int i=0,a; i<n; i++){
        // scanf("%d",&a);
        cin>>a;
        pp=queryEverything(a);
        par=pp.second.second;
        if(par!=0){
            depth[a]=depth[par]+1;
            finalAns+=depth[a];
            cout<<finalAns<<'\n';
            // printf("%lld\n",finalAns);
        }else{
            // printf("0\n");
            cout<<0<<'\n';
        }
        r={pp.first,pp.second.first};

        updateRangeEverything(r.first,r.second,-r.first,-r.second,-par);
        updateRangeEverything(r.first,a-1,r.first,a-1,a);
        updateRangeEverything(a+1,r.second,a+1,r.second,a);
    }
    return 0;
}
