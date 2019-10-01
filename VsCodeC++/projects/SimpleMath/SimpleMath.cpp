#include <bits/stdc++.h>

using namespace std;
#define MM 1000000007
pair<long long,long long> nodes[300001];
bool visited[300001];
vector<pair<int,long long>> graph[300001];
int numCycle[300001];
long long sumCycle[300001];
int main() {
    memset(visited,false,sizeof(visited));
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n;i++)nodes[i]={1,k};
    for(int i=0,a,b; i<m; i++){
        long long c;
        scanf("%d %d %lld",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    long long finalAns=1;
    bool hasOverflowed=false;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            long long ans=k;
            numCycle[i]=1;
            sumCycle[i]=0;
            stack<pair<long long,long long>> s;
            s.push({i,0});
            while(!s.empty()){
                long long t=s.top().first; long long par=s.top().second;s.pop();
                visited[t]=true;
                for(pair<int,long long> g:graph[t]){
                    pair<long long,long long> h=nodes[g.first];
                    nodes[g.first]={max(h.first,g.second-nodes[t].second),min(g.second-nodes[t].first,h.second)};
                    ans=min(ans,max(nodes[g.first].second-max(nodes[g.first].first,1LL)+1,0LL));
                    if(ans<0)hasOverflowed=true;
                    if(!visited[g.first]){
                        s.push({g.first,t});
                        numCycle[g.first]=numCycle[t]+1;
                        sumCycle[g.first]=g.second-sumCycle[t];
                    }
                    //We need to also check if this cycle would even have a possible value
                    //Aka check if it's 1 or 0
                    else if(g.first!=par){
                        if(numCycle[t]-numCycle[g.first]%2){
                            //Odd
                            long long sum=sumCycle[t]-sumCycle[g.first];

                        }else{
                            //Even
                            long long sum=sumCycle[t]+sumCycle[g.first];
                            if(sum==g.second){
                                ans=min(ans,1LL);
                            }
                            else ans=0;
                        }
                    }
                }
            }
            finalAns*=ans%MM;
            if(finalAns<0)hasOverflowed=true;
            finalAns%=MM;
        }
    }
    printf("%lld\n",finalAns);
    return 0;
}
