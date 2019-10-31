/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 15, 2019, 11:33 p.m.
 */

#include <string>
#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */

int a[100000];
int size;
int dp[100000];

int main() {
    //This is wrong
    int size;
    scanf("%d",&size);
    int a[size];
    int dp[size];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<size; i++)scanf("%d",&a[i]);
    int max=1;
    dp[0]=1;
    
    for(int i=1; i<size; i++){
        int tMax=0;
        for(int j=i-1; j>=0; j--){
            tMax=(a[j]&a[i])!=0&&dp[j]>tMax?dp[j]:tMax;
            if(tMax==max)break;
        }
        tMax++;
        dp[i]=tMax;
        max=tMax>max?tMax:max;
    }
    printf("%d",max);
}

