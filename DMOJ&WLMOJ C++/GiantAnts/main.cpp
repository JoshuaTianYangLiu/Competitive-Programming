/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 23, 2019, 1:36 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
bool visited[101];
//0 not 1 vis 2 ant
vector<int> g[101];
int main() {
    int nodes,edges;
    scanf("%d %d",&nodes,&edges);
    for(int i=0; i<edges; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int size;
    scanf("%d",&size);
    queue<int> ant;
    for(int i=0; i<size; i++){
        int a;
        scanf("%d",&a);
        ant.push(a);
        visited[a]=true;
    }
    queue<pair<int,int>> q;
    q.push({0,1});
    while(!q.empty()){
        pair<int,int> t=q.front();
        if(t.first%4==0&&t.first!=0){
            int antSize=ant.size();
            for(int i=0; i<antSize; i++){
                int t1=ant.front();
                ant.pop();
                for(int j=0; j<g[t1].size(); j++){
                    if(!visited[g[t1][i]]){
                        visited[g[t1][i]]=true;
                        ant.push(g[t1][i]);
                    }
//                    printf("%d\n",g[t1][i]);
                }
            }
        } 
        q.pop();
        visited[t.second]=true;
        for(int i=0; i<g[t.second].size(); i++){
            if(!visited[g[t.second][i]]){
                q.push({t.first+1,g[t.second][i]});
                if(g[t.second][i]==nodes){
                    if(t.first+1==8)printf("sacrifice bobhob314");
                    else printf("%d",t.first+1);
                    return 0;
                }
//                printf("%d %d\n",g[t.second][i],t.first+1);
            }
        }
        
    }
    printf("sacrifice bobhob314");
    //I find this a logistical nightmare
}

