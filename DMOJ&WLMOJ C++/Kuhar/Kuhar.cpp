/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 4, 2019, 8:41 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int m,n,x[101],y[101],sml[101],smP[101],lrg[101],lrP[101];
bool check(int a){
    int totCost=0;
    for(int i=1; i<=n; i++){
        int t=max(0,a*x[i]-y[i]);

        int cost=1000000000;
        for(int j=0; j*smP[i]<=m; j++){
            int q=0;
            if(j*sml[i]<t)
                q=(t-j*sml[i]+lrg[i]-1)/lrg[i];
                cost=min(cost,j*smP[i]+q*lrP[i]);
            
        }
        totCost+=cost;
    }
    return totCost<=m;
}

int main() {
    int ans;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++) scanf("%d %d %d %d %d %d",&x[i],&y[i],&sml[i],&smP[i],&lrg[i],&lrP[i]);
    int low=0,high=1000000;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    printf("%d",ans);
}

