/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 17, 2019, 3:18 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int size;
int a[21][21];
int dp[21][21];
int f(int pos,bool taken[]);
int main() {
    //Wrong
    scanf("%d",&size);
    bool taken[size];
    memset(dp, -1, sizeof(dp[0][0]) *21* 21);
    memset(taken, false, sizeof(taken));
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)scanf("%d",&a[i][j]);
    }
    printf("%d",f(0,taken));
}
int f(int pos,bool taken[]){
    //if(pos+1==size&&a[pos][i]==1)return 1;
    int b=0;
    for(int i=0; i<size; i++){
        if(!taken[i]&&a[pos][i]==1){
            taken[i]=true;
            b+=f(pos+1,taken);
            b%=1000000007;
        }
    }
    return b;
}

