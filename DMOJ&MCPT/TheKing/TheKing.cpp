/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 30, 2019, 10:02 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
long dp[1<<11][10][100];
//Taken     Which line  # of kings
int n;
long f(int pos,int line,int taken,int left){
    if(left==0)return 0;
    if(line==n)return 0;
    
    int t=taken;
    taken=taken|1<<pos;
    if(pos!=0)taken=taken|1<<(pos-1);
    if(pos!=n)taken=taken|1<<(pos+1);
    long out;
    if(pos>=n){
        if(dp[t][line][left]!=-1)return dp[t][line][left];
        out= f(0,line+1,t,left);
        dp[t][line][left]=out;
    }
    else if((t&(1<<pos))==0){
        if(left==1)out=f(pos+1,line,t,left)+1;
        else out=f(pos+1,line,t,left)+f(pos+2,line,taken,left-1);
    }
    else{
        t&=~(1<<pos);
        out= f(pos+1,line,t,left);
    }
    return out;
}
int main() {
    //This works... somehow
    int k;
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&k);
    long tot=f(0,0,0,k);
    printf("%lld",tot);
}

