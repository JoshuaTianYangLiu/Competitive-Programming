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
char start[1000001],end[1000001];
int dp[1000001];
int n;
int g1(int s,int e){
    int t=0;
    for(int i=s; i<e; i++){
        t+=start[i]-'0';
    }
    return t;
}
int g2(int s,int e){
    int t=0;
    for(int i=s; i<e; i++){
        t+=end[i]-'0';
    }
    return t;
}
int f(int a){
    if(a==n)return 0;
    if(a>n)return -1;
    if(start[a]==end[a])return f(a+1);
    if(start[a]=='0'&&end[a]=='1')return f(a+1)+1;
    int moveThr=f(a+3),moveFor=f(a+4);
}
int main() {
    scanf("%d",&n);
    scanf("%s\n%s",start,end);
    printf("%d",f(0));

}

