/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 23, 2019, 7:09 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int dX[]={0,0,0,0,-1,1};
int dY[]={0,0,1,-1,0,0};
int dZ[]={1,-1,0,0,0,0};
int g[101][101][101];
int main() {
    memset(g,0,sizeof(g));
    int w,l,h;
    scanf("%d %d %d",&w,&l,&h);
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        g[x][y][z]=-1;
    }
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{1,1}});
    while(!q.empty()){
        pair<int,pair<int,int>> t=q.front();
        q.pop();
        int x=t.first;
        int y=t.second.first;
        int z=t.second.second;
        if(y==l){
            if(x>=w-2&&x<=w&&z>=l-2&&z<=l){
                printf("%d",g[x][y][z]);
                return 0;
            }
        }
        for(int i=0; i<6; i++){
            int x1=x+dX[i];
            int y1=y+dY[i];
            int z1=z+dZ[i];
            if(x1>=1&&x1<=w&&y1>=1&&y1<=l&&z1>=1&&z1<=h){
                if(g[x1][y1][z1]==0){
                    g[x1][y1][z1]=g[x][y][z]+1;
                    q.push({x1,{y1,z1}});
                }
            }
        }
    }
}

