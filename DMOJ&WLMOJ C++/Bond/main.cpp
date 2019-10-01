/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 22, 2019, 8:53 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
double a[20][20];
double dp[1<<20];
bool checked[1<<20];
int size;
double f(int s,int bin){
    if(s==size)return 1.0;
    if(checked[bin])return dp[bin];
    double &m=dp[bin];
    checked[bin]=true;
    for(int i=0; i<size; i++){
        if((bin&(1<<i))==0){
            double t= a[s][i]*f(s+1,bin|(1<<i));
            if(t>m)m=t;
        }
        
    }
    return m;
}

int main() {
    scanf("%d",&size);
    memset(checked,false,sizeof(checked));
    memset(dp,0,sizeof(dp));
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            int t;
            scanf("%d",&t);
            a[i][j]=static_cast<float>(t)/100.0;
        }
    }
    printf("%0.7f",f(0,0)*100);
    return 0;
}

