/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 23, 2019, 4:52 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int dp[19][1<<19];
int nodes;
vector<int> g[19];
vector<int> w[19];
int f(int s,int bin){
    if(s+1==nodes)return 0;
    if(dp[s][bin]!=-1)return dp[s][bin];
    
    int m=-9999999;
    for(int i=0; i<g[s].size(); i++){
        if((bin&(1<<g[s][i]))==0){
            int t=f(g[s][i],bin|(1<<g[s][i]));
            t+=w[s][i];
            m=max(m,t);
        }
    }
    dp[s][bin]=m;
    return m;
}
int main() {
    int edges;
    scanf("%d %d",&nodes,&edges);
    memset(dp,-1,sizeof(dp[0][0])*19*1<<19);    
    for(int i=0; i<edges; i++){
        int s,e,we;
        scanf("%d %d %d",&s,&e,&we);
        g[s].push_back(e);
        w[s].push_back(we);
    }
    printf("%d",f(0,1));
}

