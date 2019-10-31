/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 20, 2019, 11:56 p.m.
 */

#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

/*
 * 
 */
int main() {
    int nodes,edges,s,e;
    scanf("%d %d %d %d",&nodes, &edges,&s,&e);
    vector<int> g[nodes+1];
    for(int i=0; i<edges; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool checked[nodes+1];
    memset(checked,false,sizeof(checked));
    queue<int> q;
    q.push(s);
    if(s==e){
        printf("GO SHAHIR!");
        return 0;
    }
    if(edges==0){
        printf("NO SHAHIR!");
        return 0;
    }
    while(!q.empty()){
        int t=q.front();
        checked[t]=true;
        q.pop();
        for(int i=0; i<g[t].size(); i++){
            if(!checked[g[t][i]]){
                checked[g[t][i]]=true;
                q.push(g[t][i]);
                if(g[t][i]==e){
                    printf("GO SHAHIR!");
                    return 0;
                }
            }
        }
    }
    printf("NO SHAHIR!");
    return 0;
}

