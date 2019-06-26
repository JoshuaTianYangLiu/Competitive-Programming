/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 23, 2019, 7:48 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int dX[]={-1,0,1};
int dY[]={0,1,0};
int g[1001][1001];
int dij[1001][1001];
int main() {
    memset(dij,-1,sizeof(dij));
    int l,d;
    scanf("%d %d",&l,&d);
    for(int i=0; i<d; i++){
        for(int j=0; j<l; j++){
            scanf("%d",&g[j][i]);
        }
    }
    int eL,eD;
    scanf("%d %d",&eL,&eD);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({g[0][0],{0,0}});
    dij[0][0]=g[0][0];
    while(!pq.empty()){
        pair<int,pair<int,int>> t=pq.top();
        pq.pop();
        int dist=t.first;
        int x=t.second.first;
        int y=t.second.second;
        if(dist>dij[x][y])continue;
        for(int i=0; i<3; i++){
            int x1=x+dX[i];
            int y1=y+dY[i];
            if(x1>=0&&x1<l&&y1>=0&&y1<d){
                if(dij[x][y]+g[x1][y1]<dij[x1][y1]||dij[x1][y1]==-1){
                    dij[x1][y1]=dij[x][y]+g[x1][y1];
                    pq.push({dij[x1][y1],{x1,y1}});
                }
            }
        }
    }
    printf("%d",dij[eL][eD]);
}

