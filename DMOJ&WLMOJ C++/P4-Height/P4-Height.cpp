/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 24, 2019, 6:52 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int size;
    scanf("%d",&size);
    int a[size];
    scanf("%d",&a[0]);
    int dp[size],sum[size];
    dp[0]=a[0];
    int m=a[0];
    for(int i=1; i<size; i++){
        scanf("%d",&a[i]);
        int curM=0;
        for(int j=i-1; j>=0; j--){
            if(a[j]<a[i]) curM=max(curM,dp[j]);
            if(curM==m)break;
        }
        dp[i]=curM+a[i];
        m=max(m,dp[i]);
    }
    printf("%d",m);
}

