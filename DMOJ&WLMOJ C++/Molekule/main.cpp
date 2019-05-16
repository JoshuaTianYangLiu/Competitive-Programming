/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 13, 2019, 6:12 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
vector<int> g[100001];
queue<int> q;
int dp[100001];
int main() {
    int n;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        q.push(a);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q2;
    q2.push(1);
    dp[1]=1;
    while(!q2.empty()){
        int t=q2.front();
        q2.pop();
        for(int i=0;i<g[t].size(); i++){
            if(dp[g[t][i]]==-1){
                dp[g[t][i]]=abs(dp[t]-1);
                q2.push(g[t][i]);
            }
        }
    }
    for(int i=1; i<n; i++){
        printf("%d\n",dp[q.front()]);
        q.pop();
    }
}

