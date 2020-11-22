/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 10, 2019, 5:37 p.m.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int arr[200001];
int main() {
    long n,m;
    scanf("%ld %ld",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int a=0,b=0;
    long curSum=0;
    int ans=0;
    while(b!=n){
        if(curSum<m){
            curSum+=arr[b++];
        }else{
            curSum-=arr[a++];
        }
        if(curSum<m)
            ans=max(ans,b-a);
    }
    printf("%d",ans);
}