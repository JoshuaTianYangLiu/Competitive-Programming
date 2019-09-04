/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 1, 2019, 7:50 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
vector<int> g[100001];
int num[100001],low[100001];
int artRoot=1;
int dfsCounter=1;
void artP(int u){
    num[u]=low[u]=dfsCounter++;
    for(int i=0; i<g[u].size(); i++){
        
    }
}
int main() {
    memset(num,0,sizeof(num));
    memset(low,0,sizeof(low));
    int v,e;
    scanf("%d %d",&v,&e);
    for(int i=0; i<size; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    artP(1);
    
}

