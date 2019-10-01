/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 22, 2019, 12:00 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
bool in[26][26];
int dX[]={-1,0,1,0};
int dY[]={0,1,0,-1};
int l,w;
bool bet(int v,int s,int e){return v>=s&&v<=e;}
int ff(int x,int y){
    if(!(bet(x,0,w-1)&&bet(y,0,l-1)))return 0;
    if(in[x][y])return 0;
    int ans=1;
    in[x][y]=true;
    for(int i=0; i<4; i++) ans+=ff(x+dX[i],y+dY[i]);
    return ans;
}
int main() {
    int numOfFloor;
    scanf("%d %d %d",&numOfFloor,&l,&w);
    for(int i=0; i<l; i++){
        char t[26];
        scanf("%s",t);

        for(int j=0; j<w; j++){
            in[j][i]= (t[j]=='I');
        }
        
    }
    
    vector<int> rooms;
    for(int i=0; i<l; i++){
        for(int j=0; j<w; j++){
            if(!in[j][i]){
                rooms.push_back(ff(j,i));
            }
        }
    }
    sort(rooms.begin(),rooms.end());
    for(int i=rooms.size()-1; i>=0; i--){
        if(rooms[i]>numOfFloor){
            if(rooms.size()-1-i==1)printf("%u room, %d square metre(s) left over",rooms.size()-1-i,numOfFloor);
            else printf("%u rooms, %d square metre(s) left over",rooms.size()-1-i,numOfFloor);
            return 0;
        }else{
            numOfFloor-=rooms[i];
        }
    }
    if(rooms.size()==1)printf("%u room, %d square metre(s) left over",rooms.size(),numOfFloor);
    else printf("%u rooms, %d square metre(s) left over",rooms.size(),numOfFloor);
}

