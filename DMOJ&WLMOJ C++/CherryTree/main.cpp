/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 14, 2019, 1:49 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
vector<pair<int,int>> g[10001];
int in[10001];
int wei[10001],num[10001];
int main() {
    int n,tot,w;
    scanf("%d %d %d",&n,&tot,&w);
    memset(wei,-1,sizeof(wei));
    memset(num,0,sizeof(num));
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    for(int i=1; i<n; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int out=0;
    for(int i=n; i>0; i--){
        wei[i]=0;
        num[i]=in[i];
        for(int j=0; j<g[i].size(); j++){
            if(wei[g[i][j].first]==-1){
                wei[i]+=g[i][j].second;
            }else{
                num[i]+=num[g[i][j].first];
                wei[i]+=wei[g[i][j].first];
            }
        }
        if(wei[i]<=w&&num[i]>=tot&&i!=1){
            out++;
            
        }
    }
    printf("%d",out);
}