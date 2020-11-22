/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 18, 2019, 5:53 p.m.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int r[1414215];
int d(long a,long b){
    return ceil(sqrt(a*a+b*b));
}
int main() {
    memset(r,0,sizeof(r));
    int n,q;
    scanf("%d %d",&n,&q);
    int maxR=0;
    for(int i=0; i<n; i++){
        long a,b;
        scanf("%ld %ld",&a,&b);
        int s=d(a,b);
        r[s]++;
    }
    for(int i=0; i<1414215; i++){
        r[i]+=r[i-1];
    }
    for(int i=0; i<q; i++){
        int t;
        scanf("%d",&t);
        printf("%d\n",r[t]);
    }
}