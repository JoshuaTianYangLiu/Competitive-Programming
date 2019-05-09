/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 25, 2019, 10:13 a.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int dp[251][251][251];
int tot,peo;
int f(int pers,int pi,int t){
    if(pers+1==peo)return 1;
    if(dp[t][pers][pi]!=-1)return dp[t][pers][pi];
    int cnt=0;
    for(int i=t; i<=pi/(peo-pers); i++){
        cnt+=f(pers+1,pi-i,i);
    }
    dp[t][pers][pi]=cnt;
    return cnt;
}
int main() {
    memset(dp,-1,sizeof(dp[0][0])*251*251);
    scanf("%d %d",&tot,&peo);
    printf("%d",f(0,tot,1));

}

