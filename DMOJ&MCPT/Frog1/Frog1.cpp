/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 10, 2019, 6:20 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int a[100001];
int dp[100001];
int size;
int k;
int f(int b){
    if(dp[b]!=-1)return dp[b];
    if(b==size-1)return 0;
    int min=INT_MAX;
    int d = k<size-b-1?k:size-b-1;
    for(int i=1; i<=d; i++){
        int c = abs(a[b]-a[b+i])+f(b+i);
        min=c<min?c:min;
    }
    dp[b]=min;
    return dp[b];
}
int main() {
    
    scanf("%d %d",&size,&k);
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<size; i++){
        scanf("%d\n",&a[i]);
        dp[i]=-1;
    }
    printf("%d",f(0));

}

