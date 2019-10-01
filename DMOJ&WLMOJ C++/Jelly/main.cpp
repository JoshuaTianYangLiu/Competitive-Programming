/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 29, 2019, 9:29 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
//Way too much effort to code
//Modified dijkstra
//3d gt problems are not worth the time
int g[151][151][151];
int dX[]={1,-1,0,0,0,0};
int dY[]={0,0,1,-1,0,0};
int dZ[]={0,0,0,0,1,-1};
int main() {
    int x,y,z;
    int sX,sY,sZ;
    scanf("%d %d %d",&x,&y,&z);
    for(int i=0; i<z; i++){
        for(int j=0; j<y; j++){
            char t[151];
            scanf("%s",t);
            for(int k=0; k<x; k++){
                if(t[k]=='J'){
                    g[k][j][i]=0;
                    sX=k;sY=j;sZ=i;
                }else{
                    g[k][j][i]=t[k]-'0';
                }
            }
        }
    }
    
}

