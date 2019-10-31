/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 27, 2019, 2:49 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int a[1001],b[1001];
int sA,sB;
int dp[1001][1001];
int f(int m,int n){
    if(m==sA||n==sB)return 0;
    if(dp[m][n]!=-1)return dp[m][n];
    int t;
    if(a[m]==b[n])t=f(m+1,n+1)+1;
    else t= max(f(m+1,n),f(m,n+1));
    dp[m][n]=t;
    return t;
}
int main() {
    scanf("%d %d",&sA,&sB);
    memset(dp,-1,sizeof(dp[0][0])*1001*1001);
    for(int i=0; i<sA; i++)scanf("%d",&a[i]);
    for(int i=0; i<sB; i++)scanf("%d",&b[i]);
    printf("%d",f(0,0));
}

