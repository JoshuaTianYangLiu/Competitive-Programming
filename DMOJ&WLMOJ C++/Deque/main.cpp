/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 12, 2019, 7:24 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int in[3001];
long dp[3001][3001];
long f(int s,int e){
    if(s==e)return in[s];
    if(e<s)return 0;
    if(dp[s][e]!=-1)return dp[s][e];
    //left
    long l=min(f(s+1,e-1)-in[e],f(s+2,e)-in[s+1]);
    long r=min(f(s+1,e-1)-in[s],f(s,e-2)-in[e-1]);
    return dp[s][e]=max(l+in[s],r+in[e]);
    
}
int main() {
    int size;
    scanf("%d",&size);
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<size; i++)scanf("%d",&in[i]);
    printf("%ld",f(0,size-1));

}

