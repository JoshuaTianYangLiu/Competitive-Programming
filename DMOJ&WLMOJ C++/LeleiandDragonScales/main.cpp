/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 11, 2019, 11:47 a.m.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int g[252][252];
int f(int a,int b, int c, int d){
    return g[c][d]-g[a-1][d]-g[c][b-1]+g[a-1][b-1];
}
int main() {
    memset(g,0,sizeof(g));
    int w,h,n;
    scanf("%d %d %d",&w,&h,&n);
    for(int i=1; i<=h; i++){
        for(int j=1; j<= w; j++){
            scanf("%d",&g[i][j]);
            g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=1; i<=h; i++){
        bool u=true;
        for(int j=1; j<=w; j++){
            for(int k=j; k<=w; k++){
                int t=n/(k-j+1);
                if(i+t-1<=h){
                    ans=max(ans,f(i,j,i+t-1,k));
                    u=false;
                }
            }
        }
        if(u)break;
    }
    printf("%d",ans);
}