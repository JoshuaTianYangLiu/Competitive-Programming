/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 4, 2019, 8:04 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int dp[26][26];
int main() {
    int r,c;
    scanf("%d %d",&r,&c);
    int n;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        dp[a][b]=-1;
    }
    dp[1][0]=1;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(dp[i][j]!=-1){
                dp[i][j]=max(dp[i-1][j],0)+max(dp[i][j-1],0);
            }
        }
    }
    printf("%d",dp[r][c]);
}

