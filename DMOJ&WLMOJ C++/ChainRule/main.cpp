/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 22, 2019, 5:52 p.m.
 */

#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;
/*
 * 
 */
int INF=INT_MAX;
vector<pair<int,int>> g[100001];
int dist[100001];
//to    -   weight
void dij(int s){
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()){
        ii t=pq.top();
        pq.pop();
        int dist1=t.first;
        int from=t.second;
        if(dist1>dist[from])continue;
        for(int i=0; i<g[from].size(); i++){
            ii t1=g[from][i];
            if(dist[from]+t1.second<dist[t1.first]){
                dist[t1.first]=dist[from]+t1.second;
                pq.push({dist[t1.first],t1.first});
//                printf("%d %d %d\n",from,t1.first,dist[t1.first]);
            }
        }
    }
}
int distS[100001];
int main() {
    int nodes,edges;
    scanf("%d %d",&nodes,&edges);
    for(int i=0; i<edges; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    memset(dist,INF,sizeof(dist));
    dij(0);
    for(int i=0; i<nodes; i++){
        distS[i]=dist[i];
//        printf("%d ",dist[i]);
    }
    memset(dist,INF,sizeof(dist));
    dij(nodes-1);
    int ans=0;
    for(int i=0; i<nodes; i++){
        ans=max(ans,distS[i]+dist[i]);
    }
    printf("%d",ans);
}

