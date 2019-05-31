/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 18, 2019, 6:19 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int rank1[100001],point[100001];
int fSet(int a){ return point[a]==a?a:point[a]=fSet(point[a]);}
bool isSameSet(int a,int b){return fSet(a)==fSet(b);}
void uSet(int a, int b){
    if(!isSameSet(a,b)){
        int x=fSet(a),y=fSet(b);
        if(rank1[x]>rank1[y])point[y]=x;
        else{
            point[x]=y;
            if(rank1[x]==rank1[y])
                rank1[y]++;
        }
    }
}
vector<int> g[100001];
pair<bool,int> went1[100001],went2[100001];
int main() {
    memset(rank1,0,sizeof(rank1));
    int nodes,edges,que;
    scanf("%d %d %d",&nodes,&edges,&que);
    
    for(int i=1; i<=edges; i++){
        point[i]=i;
        int a,b;
        scanf("%d %d",&a,&b);
        uSet(a,b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0; i<que; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(isSameSet(a,b)){
            //BFS
            memset(went1,true,sizeof(went1));
            memset(went2,true,sizeof(went2));
            queue<pair<int,int>> q1,q2;
            q1.push({a,0});
            q2.push({b,0});
            went1[a]={false,0};
            went2[b]={false,0};
            while(true){
                pair<int,int> v=q1.front();
                q1.pop();
                if(!went2[v.first].first){
                    printf("%d\n",v.second+went2[v.first].second);
                    break;
                }
                for(int j=0; j<g[v.first].size(); j++){
                    if(went1[g[v.first][j]].first){
                        went1[g[v.first][j]]={false,v.second+1};
                        q1.push({g[v.first][j],v.second+1});
                    }
                }
                v=q2.front();
                q2.pop();
                if(!went1[v.first].first){
                    printf("%d\n",v.second+went1[v.first].second);
                    break;
                }
                for(int j=0; j<g[v.first].size(); j++){
                    if(went2[g[v.first][j]].first){
                        went2[g[v.first][j]]={false,v.second+1};
                        q2.push({g[v.first][j],v.second+1});
                    }
                }
                
            }
        }else{
            printf("-1\n");
        }
    }
}

