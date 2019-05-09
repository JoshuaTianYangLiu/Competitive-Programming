/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 13, 2019, 8:04 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    
    int n;
    scanf("%d",&n);
    int pre[n];
    int suf[n];
    int a[n];
    
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(i!=0)pre[i]=max(a[i],pre[i-1]);
        else pre[i]=a[i];
    }
    unsigned long long total=0;
    for(int i=n-1; i>=0; i--){
        if(i!=n-1)suf[i]=max(a[i],suf[i+1]);
        else suf[i]=a[i];
        total+=min(pre[i],suf[i])-a[i];
    }
    printf("%llu\n",total);
}

