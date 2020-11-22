/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 22, 2019, 11:44 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int g[400001],v[400001];
int main() {
    int size;
    scanf("%d",&size);
    for(int i=1; i<size; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[b]=a;
    }
    for(int i=1; i<=size; i++){
        int a;
        scanf("%d",&a);
        v[i]=a;
    }
    int ans=v[size];
    for(int i=size; i>1; i--){
        int pointTo=g[i];
        v[pointTo]+=v[i];
        ans=max(ans,v[i]);
    }
    ans=max(ans,v[1]);
    printf("%d",ans);
}

