/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 26, 2019, 7:39 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int in[1501][1501];
bool visited[1501][1501];
int dX[]={-1,1,0,0};
int dY[]={0,0,1,-1};
int main() {
    int size,h;
    memset(visited,false,sizeof(visited));
    scanf("%d %d",&size,&h);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            scanf("%d",&in[i][j]);
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> t = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int x=t.second+dX[i];
            int y=t.first+dY[i];
            if(x>=0&&x<size&&y>=0&&y<size){
                if(!visited[y][x]){
                    if(abs(in[t.first][t.second]-in[y][x])<=h)
                    q.push({y,x});
                }
                visited[y][x]=true;
            }
        }
    }
    printf("%s",visited[size-1][size-1]?"yes":"no");
}

