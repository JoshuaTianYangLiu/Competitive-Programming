/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 6, 2019, 12:16 a.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
vector<int> g[100001];
long dp[100001],poss[100001];
int main() {
    int v,e;
    scanf("%d %d",&v,&e);
    memset(dp,0,sizeof(dp));
    memset(poss,0,sizeof(poss));
    for(int i=0; i<e; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
    }
    long tot=0;
    for(int i=1; i<=v; i++){
        for(int j=0; j<g[i].size(); j++){
            long t=0;
            if(poss[i]>1)t=poss[i];
            else t=1;
            poss[g[i][j]]+=t;
            poss[g[i][j]]%=1000000007;
            dp[g[i][j]]+=dp[i]+t;
            dp[g[i][j]]%=1000000007;
        }
        if(g[i].size()==0){
            tot+=dp[i];
            tot%=1000000007;
        }
    }
//    for(int i=1; i<=v; i++)printf("%d ",dp[i]);
//    printf("\n");
//    for(int i=1; i<=v; i++)printf("%d ",poss[i]);
//    printf("\n");
    int out=tot%=1000000007;
    printf("%d",out);
}

