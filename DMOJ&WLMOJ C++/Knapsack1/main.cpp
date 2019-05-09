/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 27, 2019, 3:29 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */


int main() {
    
    int size, tW;
    scanf("%d %d",&size,&tW);
    int v[size+1], w[size+1];
    long long dp[tW+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<size; i++)scanf("%d %d",&w[i],&v[i]);
    for(int i=0; i<=size; i++){
        for(int j=tW; j>=0; j--){
            if(j==0||i==0)dp[j]=0;
            else if(w[i-1]<=j) dp[j] =max(v[i-1]+ dp[j-w[i-1]],dp[j]); 
            else dp[j]=dp[j]; 
        }
    }
    printf("%lld",dp[tW]);
}

