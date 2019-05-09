/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 28, 2019, 2:14 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int size,a[101];
int dp[5281];
int f(int t){
    if(t==0)return 0;
    if(t<0)return INT_MAX;
    if(dp[t]!=-1)return dp[t];
    int out=INT_MAX;
    for(int i=0; i<size; i++){
        out=min(f(t-a[i]),out);
    }
    if(out!=INT_MAX)dp[t]=++out;
    return out;
}
int main() {
    memset(dp,-1,sizeof(dp));
    int tot;
    scanf("%d\n%d",&tot,&size);
    for(int i=0; i<size; i++)scanf("%d",&a[i]);
    if(f(tot)==INT_MAX)printf("Roberta acknowledges defeat.");
    else printf("Roberta wins in %d strokes.",f(tot));

}

