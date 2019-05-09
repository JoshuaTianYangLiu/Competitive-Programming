/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 24, 2019, 9:32 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */

int main() {
    int v;
    scanf("%d",&v);
    vector<int> g[v+1];
    int dp[v+1];
    int a,b;
    scanf("%d %d",&a,&b);
    while(a!=0&&b!=0){
        g[a].push_back(b);
        scanf("%d %d",&a,&b);
    }
    memset(dp,0,sizeof(dp));
    dp[v]=1;
    for(int i=v-1; i>0; i--){
        int n=0;
        for(int j=0; j<g[i].size(); j++){
            n+=dp[g[i][j]];
        }
        dp[i]=n;
    }
    printf("%d",dp[1]);
}

