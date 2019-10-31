/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 26, 2019, 11:14 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
typedef pair<int,int> ii;
vector<pair<int,int>> g[2001];
int dist[2001];
int main() {
    memset(dist,-1,sizeof(dist));
    int node,edge,b,q;
    scanf("%d %d %d %d",&node,&edge,&b,&q);
    for(int i=0; i<edge; i++){
        int a,c,d;
        scanf("%d %d %d",&a,&c,&d);
        g[a].push_back({c,d});
        g[c].push_back({a,d});
    }
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,b});
    dist[b]=0;
    while(!pq.empty()){
        ii t=pq.top();
        pq.pop();
        int dist1=t.first;
        int from=t.second;
        if(dist1>dist[from])continue;
        for(int i=0; i<g[from].size(); i++){
            ii t1=g[from][i];
            if(dist[from]+t1.second<dist[t1.first]||dist[t1.first]==-1){
                dist[t1.first]=dist[from]+t1.second;
                pq.push({dist[t1.first],t1.first});
            }
        }
    }
    for(int i=0; i<q; i++){
        int a;
        scanf("%d",&a);
        printf("%d\n",dist[a]);
    }
}

