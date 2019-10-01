/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 22, 2019, 4:30 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
vector<int> g[1000001];
bool checked[1000001];
int bfs(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        checked[t]=true;
        for(int i=0; i<g[t].size(); i++){
            if(!checked[g[t][i]])q.push(g[t][i]);
        }
    }
}
int main() {
    int size,edges;
    scanf("%d %d",&size,&edges);
    for(int i=0; i<edges; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
    }
    int s,e;
    scanf("%d %d",&s,&e);
    memset(checked,false,sizeof(checked));
    bfs(s);
    if(checked[e]){
        printf("yes");
        return 0;
    }
    memset(checked,false,sizeof(checked));
    bfs(e);
    if(checked[s]){
        printf("no");
        return 0;
    }
    printf("unknown");
}

