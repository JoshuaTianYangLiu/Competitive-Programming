/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 29, 2019, 8:26 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
vector<pair<int,pair<int,int>>> g[1001];
double v[1001];
int in[1001];
int p[1001];
int main() {
    int size;
    for(int i=0; i<1001; i++)p[i]=1;
    scanf("%d",&size);
    for(int i=1; i<size; i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        g[a].push_back({b,{c,d}});
    }
    for(int i=1; i<=size; i++)scanf("%d",&in[i]);
    v[1]=1.0;
    double ans=0;
    for(int i=1; i<=size; i++){
        for(int j=0; j<g[i].size(); j++){
            pair<int,pair<int,int>> t;
            t=g[i][j];
            v[t.first]=v[i]*t.second.first/100.0;
            if(t.second.second==1){
                v[t.first]*=v[t.first];
                p[t.first]=p[i]*2;
            }else{
                p[t.first]=p[i];
            }
        }
        if(in[i]!=-1){
            double t=pow(in[i],1.0/p[i])/pow(v[i],1.0/p[i]);
            ans=max(ans,t);
            
        }
    }
    printf("%f",ans);
}

