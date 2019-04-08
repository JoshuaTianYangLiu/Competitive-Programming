/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 7, 2019, 10:03 p.m.
 */

#include <bits/stdc++.h>

using namespace std;
int a[2001][2001];
int main() {

    
    for(int c=0;c<2001; c++){
        for(int b=0;b<2001;b++){
            a[c][b]= 0;
            
        }
    }
    for(int i = 1; i<2001; i++){
        a[0][i]=1;
    }
    for(int i =2; i<2001; i++){
        for(int j=i;j<2001; j++){
            a[i-1][j]=(a[i-1][j]%1000000007+a[i-2][j]%1000000007)%1000000007;
            a[i-1][j]=(a[i-1][j]%1000000007+a[i-1][j-1]%1000000007)%1000000007;
        }
    }
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        int c,b;
        scanf("%d-%d",&c,&b);
        printf("Case #%d: %d %d",i+1,a[b][c],a[b][b+1]);
    }
}