/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 27, 2019, 10:22 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int a[1001];
long dp[1001][1001];
long long f(int n,int k){
    if (k==0){
        return 1;
    }
    if (n==0){
        return 0;
    }
    if(dp[n][k]!=-1)return dp[n][k];
    dp[n][k]= f(n-1,k)%998244353+(a[n]*f(n-1,k-1))%998244353;
    return dp[n][k];
}

int main() {
    int size;
    scanf("%d",&size);
    int k;
    scanf("%d",&k);
    int temp;
    for(int i=0; i<size; i++){
        scanf("%d",&temp);
        a[temp]++;
    }
    for(int i=0; i<=size; i++){
        for(int j=0; j<=k; j++){
            dp[i][j]=-1;
        }
    }
    printf("%lld\n",f(size,k));

}

