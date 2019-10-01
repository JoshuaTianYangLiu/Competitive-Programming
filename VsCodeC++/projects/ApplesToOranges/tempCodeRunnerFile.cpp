#include <bits/stdc++.h>

using namespace std;
map<string,int> ma;
vector<pair<int,double>> g[501];
double val[501];
bool visited[501];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        char in[26];
        scanf("%s ",in);
        ma[in]=i;
    }
    for(int i=0; i<m; i++){
        double a;
        char in1[26],in2[26];
        scanf("%s %s %lf",in1,in2,&a);
        g[ma[in1]].push_back({ma[in2],a});
    }
    int s=ma["APPLES"];
    priority_queue<pair<double,int>> pq;
    pq.push({1,s});
    val[s]=1;
    while(!pq.empty()){
        pair<double,int> t=pq.top(); pq.pop();
        if(t.first<val[t.second])continue;
        for(pair<int,double> u:g[t.second]){
            if(val[t.second]*u.second>val[u.first]){
                val[u.first]=val[t.second]*u.second;
                pq.push({val[u.first],u.first});
            }
        }
    }
    if(val[s]>1)printf("YA");
    else printf("NAW");
    return 0;
}
