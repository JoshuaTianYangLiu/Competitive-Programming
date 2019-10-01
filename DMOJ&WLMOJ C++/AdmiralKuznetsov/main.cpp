/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 13, 2019, 10:48 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
char start[1000001],end1[1000001];
int dp[1000001];
int n;
int g1(int s,int e){
    int t=0;
    for(int i=s; i<min(e,n); i++){
        t+=start[i]-'0';
    }
    return t;
}
int g2(int s,int e){
    int t=0;
    for(int i=s; i<min(e,n); i++){
        t+=end1[i]-'0';
    }
    return t;
}
int minNum(int a,int b){
    if(a==-1)return b;
    if(b==-1)return a;
    return min(a,b);
}
int f(int a){
    if(dp[a]!=-1)return dp[a];
    if(a==n)return 0;
    if(a>n)return 0;
    if(start[a]=='0') return dp[a]=minNum(f(a+1)+g2(a,a+1),minNum(f(a+4)+5-g1(a,a+4)+g2(a,a+4),f(a+3)+4-g1(a,a+3)+g2(a,a+3)));
    if(start[a]=='1'&&end1[a]=='0') return dp[a]=minNum(f(a+4)+5-g1(a,a+4)+g2(a,a+4),f(a+3)+4-g1(a,a+3)+g2(a,a+3));
    if(start[a]=='1'&&end1[a]=='1') return dp[a]=minNum(f(a+1),minNum(f(a+4)+5-g1(a,a+4)+g2(a,a+4),f(a+3)+4-g1(a,a+3)+g2(a,a+3)));
}
int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    scanf("%s\n%s",start,end1);
    printf("%d",f(0));

}

