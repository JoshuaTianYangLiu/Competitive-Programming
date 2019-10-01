/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 23, 2019, 8:38 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
typedef pair<int,int> ii;
bool isMarket[2001];
vector<pair<int,int>> graph[2001];
int dist[2001];
int main() {
    memset(isMarket,false,sizeof(isMarket));
    memset(dist,-1,sizeof(dist));
    int t,n,m,g;
    scanf("%d %d %d %d",&t,&n,&m,&g);
    for(int i=0; i<g; i++){
        int a;
        scanf("%d",&a);
        isMarket[a]=true;
    }
    for(int i=0; i<m; i++){
        int a,b,l;
        scanf("%d %d %d",&a,&b,&l);
        graph[a].push_back({b,l});
    }
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(d>dist[node])continue;
        for(int i=0; i<graph[node].size(); i++){
            if(dist[node]+graph[node][i].second<dist[graph[node][i].first]
                    ||dist[graph[node][i].first]==-1){
                dist[graph[node][i].first]=dist[node]+graph[node][i].second;
                pq.push({dist[graph[node][i].first],graph[node][i].first});
            }
        }
    }
    int ans=0;
    for(int i=1; i<n; i++){
        if(isMarket[i]&&dist[i]<t&&dist[i]!=-1)ans++;
    }
    printf("%d",ans);
}

