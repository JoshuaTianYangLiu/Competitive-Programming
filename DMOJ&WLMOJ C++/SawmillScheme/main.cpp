/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 9, 2019, 11:58 a.m.
 */

#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

/*
 * 
 */
vector<int> g[1000001] ;
double size[1000001];
int main() {
    
    int nodes;
    int edges;
    scanf("%d %d",&nodes,&edges);
    for(int i=0; i<edges; i++){
        int b;
        int c;
        scanf("%d %d",&b,&c);
        g[b].push_back(c);
    }
    size[1]=1.0;
    for(int i=1; i<=nodes; i++){
        if(g[i].size()>0){
            double d = size[i]/g[i].size();
            for(int j=0; j<g[i].size(); j++){
                size[g[i][j]]+=d;
            }
        }else{
            printf("%1.9f\n",size[i]);
        }
    }
}

