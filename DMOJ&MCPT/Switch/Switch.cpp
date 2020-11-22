/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 29, 2019, 5:52 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int size;
int conv(int a){
    int out=0;
    int cnt=0;
    for(int i=size-1; i>=0; i--){
        out=out<<1;
        if((a&(1<<i))!=0){
            cnt++;
        }else{
            if(cnt<4&&cnt!=0){
                out+=(1<<cnt)-1;
            }
            cnt=0;
        }
    }
    out=out<<1;
    if(cnt<4&&cnt!=0){
        out+=(1<<cnt)-1;
    }
    return out;
}
bool flip=true;
int out=0;
int main() {
    //Bfs will not work.. .Grrr
    scanf("%d",&size);
    int to=0;
    
    for(int i=0; i<size; i++){
        to=to<<1;
        int t;
        scanf("%d",&t);
        to+=t;
    }
    map<int,int> m;
    queue<pair<int,int>> q;
    m[to]=1;
    q.push({0,to});
    while(!q.empty()){
        pair<int,int> next=q.front();
        q.pop();
        if(next.second==0){
            printf("%d",next.first);
            return 0;
        }
        for(int i=0; i<size; i++){
            int u=next.second|(1<<i);
            int w=i==0?1:next.second|(1<<(i-1));
            int x=i==size-1?1:next.second|(1<<(i+1));
            int v=conv(u);
            if((next.second&(1<<i))==0&&w*x!=0&&m.count(v)==0){
                m[v]=1;
                q.push({next.first+1,v});
            }
        }
    }
}