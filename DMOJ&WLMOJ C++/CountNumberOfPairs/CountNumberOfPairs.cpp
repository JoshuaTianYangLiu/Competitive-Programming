/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 18, 2019, 6:34 p.m.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int in[100002];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)scanf("%d",&in[i]);
    sort(in,in+n);
    long ans=0;
    int a,b;
    for(int i=2; i<=n; i++){
        if(in[i]+in[i-1]>m){
            a=i-2;
            b=i;
            break;
        }
    }
    while(true){
        
    }
    printf("%ld",ans);
}