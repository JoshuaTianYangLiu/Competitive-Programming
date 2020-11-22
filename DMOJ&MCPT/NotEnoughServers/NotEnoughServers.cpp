/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 20, 2019, 9:01 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    //Dear josh who will try this again, you should still remember how to do this
    //hopefully you know how to generate all 2^n subsets and dp them all
    //good luck
    int n,m;
    scanf("%d %d",&n,&m);
    int dp[1<<n];
    int prev[1<<n];
    int a[m];
    memset(a,0,sizeof(a));
    memset(dp,INT_MAX,sizeof(dp));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            a[j]<<1;
            char temp;
            scanf("%c",&temp);
            a[j]+=temp=='O'?0:1;
        }
    }
    dp[a[0]]=1;
    prev[a[0]]=-1;
    for(int i=1; i<m; i++){
        for(int j=0; j<i; j++){
            if(dp[])
        }
    }
}

