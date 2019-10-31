/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 21, 2019, 8:33 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int c,r;
    scanf("%d %d",&r,&c);
    int a[r];
    memset(a,0,sizeof(a));
    bool checked[1<<c];
    memset(checked,false,sizeof(checked));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int t;
            scanf("%d",&t);
            a[i]<<=1;
            a[i]+=t;
        }
    }
    int cnt=0;
    int t=0;
    for(int i=r-1; i>=0; i--){
        t^=a[i];
        if(!checked[t]){
            checked[t]=true;
            cnt++;
        }
    }
    printf("%d",cnt);
}

