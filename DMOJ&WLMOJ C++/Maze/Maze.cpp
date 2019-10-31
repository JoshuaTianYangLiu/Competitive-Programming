/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 26, 2019, 6:45 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int dX[]={1,-1,0,0};
int dY[]={0,0,1,-1};
char in[21][21];
int g[21][21];
//This is annoying
int main() {
    int cases;
    scanf("%d",&cases);
    for(int a=0; a<cases; a++){
        memset(g,-1,sizeof(g));
        int l,w;
        scanf("%d %d",&l,&w);
        for(int i=0; i<l; i++){
            char b[21];
            scanf("%s",b);
            for(int j=0; j<w; j++){
                in[i][j]=b[j];
            }
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        g[0][0]=1;
        while(!q.empty()){
            pair<int,int> t = q.front();
            q.pop();
            if(in[t.first][t.second]=='-'){
                for(int i=0; i<2; i++){
                    int x=t.second+dX[i];
                    if(x>=0&&x<=w-1){
                        if(g[t.first][t.second]+1<g[t.first][x]||g[t.first][x]==-1){
                            g[t.first][x]=g[t.first][t.second]+1;
                            q.push({t.first,x});
                        }
                    }
                }
            }
            if(in[t.first][t.second]=='|'){
                for(int i=2; i<4; i++){
                    int y=t.second+dY[i];
                    if(y>=0&&y<=l-1){
                        if(g[t.first][t.second]+1<g[y][t.second]||g[y][t.second]==-1){
                            g[y][t.second]=g[t.first][t.second]+1;
                            q.push({y,t.second});
                        }
                    }
                }
            }
            if(in[t.first][t.second]=='+'){
                for(int i=0; i<4; i++){
                    int x=t.second+dX[i];
                    int y=t.second+dY[i];
                    if(y>=0&&y<=l-1&&x>=0&&x<=w-1){
                        if(g[t.first][t.second]+1<g[y][x]||g[y][x]==-1){
                            g[y][x]=g[t.first][t.second]+1;
                            q.push({y,x});
                        }
                    }
                }
            }
        }
        if(in[l-1][w-1]=='*')printf("-1");
        else printf("%d\n",g[l-1][w-1]);
    }
}

