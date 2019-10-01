/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 31, 2019, 11:51 a.m.
 */

#include <string>
#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */

int a[1000000];
int size;
int dp[1000000];
int point;
int binary(int T){
    int l=0;
    int r=point-1;
    while (r - l > 1) { 
       int m = l + (r - l) / 2; 
       if (dp[m] >= T) 
           r = m; 
       else
           l = m; 
    } 
  
    return r; 
}
int main() {
    //This is wrong
    scanf("%d",&size);
    memset(dp,0,sizeof(dp));
    for(int i=0; i<size; i++)scanf("%d",&a[i]);
    int max1=1;
    dp[0]=a[0];
    point=1;
    for(int i=1; i<size; i++){
        
        if(a[i]<dp[0]){
            dp[0]=a[i];
        }else if(a[i]>dp[point-1]){
            dp[point++]=a[i];
        }else{
            dp[binary(a[i])]=a[i];
        }
//        for(int i=0; i<point; i++)printf("%d ",dp[i]);
//        printf("\n");
    }
    printf("%d\n",point);
    
}

