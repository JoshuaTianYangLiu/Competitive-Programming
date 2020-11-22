/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 10, 2019, 6:15 p.m.
 */


#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
//I hate this question
//Barely passes the time
bool a[10002][10002];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int b,c,d,e;
    for(int i=0; i<m; i++){
        scanf("%d %d %d %d",&b,&c,&d,&e);
        b++;
        c++;
        a[b][c]^=true;
        a[b+d][c+e]^=true;
        a[b][c+e]^=true;
        a[b+d][c]^=true;
    }
    int ans=0;
    for(int j=1; j<=n; j++){
        bool t=false;
        for(int i=1; i<=n; i++){
            t^=a[i][j];
            if(t)ans++;
            if(a[i][j])a[i][j+1]=!a[i][j+1];
        }
    }
    printf("%d",ans);
}