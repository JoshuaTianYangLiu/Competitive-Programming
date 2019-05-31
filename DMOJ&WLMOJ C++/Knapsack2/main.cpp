/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 18, 2019, 11:02 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int x[101],y[101];
bool checked[1000001];
int dp[1000001];
vector<int> in;
int main() {
    int size,totW;
    scanf("%d %d",&size,&totW);
    memset(checked,true,sizeof(checked));
    for(int i=0; i<1000001; i++)dp[i]=INT_MAX;
    for(int i=0; i<size; i++)scanf("%d %d",&x[i],&y[i]);
    checked[0]=false;
    dp[0]=0;
    in.push_back(0);
    int out=0;
    for(int i=0; i<size; i++){
        int t=in.size();
        for(int j=0; j<t; j++){
            int v=in[j]+y[i];
            if(dp[in[j]]+x[i]<=totW){
                if(checked[v]){
                    checked[v]=false;
                    in.push_back(v);
                }
                dp[v]=min(dp[in[j]]+x[i],dp[v]);
                out=max(out,v);
            }
        }
    }
    for(int i=0; i<=100; i+=10){
        printf("%d %d\n",i,dp[i]);
    }
    printf("%d",out);

}

