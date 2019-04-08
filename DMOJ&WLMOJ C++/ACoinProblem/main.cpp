/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 30, 2019, 5:34 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int coin[2000];
int dp[10001][10001];
int find(int n,int q){
    if(n==0){
        dp[n][q]=0;
        return 0;
    }
    if(n<0){
        return -1;
    }
    if(dp[n][q]!=-2)return dp[n][q];
    int min=INT_MAX;
    bool changed=false;
    for(int i=0; i<q;i++){
        int a=find(n-coin[i],q);
        if(n-coin[i]>-1)
            dp[n-coin[i]][q]=a;
        if(a!=-1){
            changed=true;
            if(a<min)min=++a;
        }
    }
    if(changed){
        return min;
    }
    return -1;
}


int main(){
    // TODO code application logic here
    int N;
    scanf("%d",&N);
    int q;
    scanf("%d",&q);
    for(int i=0; i<N; i++){
        scanf("%d",&coin[i]);
    }
    for(int i=0; i<10001; i++){
        for(int j=0; j<10001; j++){
            dp[i][j]=-2;
        }
    }

    for(int i=0; i<q; i++){
        int a;
        scanf("%d",&a);
        int b;
        scanf("%d",&b);
        int out = find(a,b);
        printf("%d\n",out);
    }
}
