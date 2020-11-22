#include <bits/stdc++.h>

using namespace std;
pair<int,int> gym[200020],gs[200020];
long long dist(pair<int,int> a,pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
vector<pair<int,int>> xThings[400040];
//Coordinate compression
int ItoR[400040];
map<int,int> RtoI;
set<int> s;
queue<pair<int,pair<int,int>>> q;
int main() {
    int n,m;
    int idToRSize=1;
    scanf("%d %d",&n,&m);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        gym[i]={a,b};
        s.insert(a);
        q.push({a,{b,1}});
    }
    for(int j=0,a,b; j<m; j++){
        scanf("%d %d",&a,&b);
        gs[j]={a,b};
        s.insert(a);
        q.push({a,{b,2}});
    }
    int idSize=1;
    for(int a:s){
        ItoR[idSize]=a;
        RtoI[a]=idSize++;
    }
    idSize--;
    while(!q.empty()){
        pair<int,pair<int,int>> coord = q.front(); q.pop();
        xThings[coord.first].push_back(coord.second);
    }
    for(int i=1; i<=idSize; i++){
        sort(xThings[i].begin(),xThings[i].end());
    }
    long long ans=2e9;
    
    for(int i=1; i<=idSize; i++){
        int sz = xThings[i].size();
        for(int i=0; i<sz; i++){
            if()
        }
    }
    printf("%lld\n",(ans+1)/2);
    return 0;
}