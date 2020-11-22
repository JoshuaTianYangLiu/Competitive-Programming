#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
pair<int,int> nodes[300001];
bool visited[300001],visited2[300001];
vector<pair<int,int>> graph[500001];
int n,m,k;
int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n;i++)nodes[i]={0,0};
    for(int i=0,a,b,c; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    long long finalAns=1;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            int lBound=1,uBound=k;
            stack<int> s;
            s.push(i);
            nodes[i]={1,0};
            while(!s.empty()){
                int t=s.top(); s.pop();
                if(nodes[t].first==1)lBound = max(lBound,1-nodes[t].second),uBound=min(uBound,k-nodes[t].second);
                else lBound = max(lBound,nodes[t].second-k),uBound=min(uBound,1-nodes[t].second);
                for(pair<int,int> u:graph[t]){
                    if(nodes[u.first].first==0)nodes[u.first]={-nodes[t].first,-nodes[t].second+u.second};
                    else{
                        if(nodes[u.first].first=-nodes[t].first&&nodes[u.first].second==-nodes[t].second+u.second);
                        //else finalAns=0;
                    }
                    if(!visited[u.first]){
                        visited[u.first]=true;
                        s.push(u.first);
                    }
                    printf("%d %d\n",nodes[u.first].first,nodes[u.second].second);
                }
            }
            if(lBound>uBound){
                printf("0\n");
                return 0;
            }
            finalAns*=uBound-lBound+1;
            finalAns%=MM;
        }
    }
    printf("%lld\n",finalAns);
    return 0;
}