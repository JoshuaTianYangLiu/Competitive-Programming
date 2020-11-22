/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 7, 2019, 3:18 p.m.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
long cake[5001][5001];
long f(int a,int b, int c, int d){
    return cake[c][d]-cake[a-1][d]-cake[c][b-1]+cake[a-1][b-1];
}
int N,M,K;
void preFix(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(j!=1)cake[i][j]+=cake[i][j-1];
        }
    }
    
    for(int j=1; j<=M; j++){
        for(int i=1; i<=N; i++){
            if(i!=1)cake[i][j]+=cake[i-1][j];
        }
    }
}
int main() {
    memset(cake,0,sizeof(cake));
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0; i<K; i++){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        cake[a][b]++;
        cake[c+1][d+1]++;
        cake[a][d+1]--;
        cake[c+1][b]--;
    }
    preFix();
     preFix();
    
     int q;
     scanf("%d",&q);
     for(int i=0; i<q; i++){
         int a,b,c,d;
         scanf("%d %d %d %d",&a,&b,&c,&d);
         printf("%ld\n",f(a,b,c,d));
     }
}