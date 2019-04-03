/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 31, 2019, 8:36 p.m.
 */


#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int n,m;
    long long k;
    scanf("%d %d %lld",&n,&m,&k);
    int a[n];
    a[0]=m;
    for(int i=1; i<n; i++)a[i]=0;
    int aS;
    int bS;
    for(int i=0; i<m; i++){
        scanf("%d %d",&aS,&bS);
        a[aS-1]--;
        if(bS<n)a[bS]++;
    }
    for(int i=1; i<n; i++)a[i]=a[i]+a[i-1];
    long long total=0;
    long long min=-1;
    int s=0;
    int i=0;
    while(i<n){
        if(total>=k){
            if(min==-1||i-s<min)min=i-s;
            total-=a[s];
            s++;
        }else{
            total+=a[i];
            i++;
        }
    }
    while(total>=k){
        if(min==-1||i-s<min)min=i-s;
        total-=a[s];
        s++;
    }
    printf("%lld",min);
}

