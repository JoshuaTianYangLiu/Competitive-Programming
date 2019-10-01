/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 26, 2019, 2:13 p.m.
 */

#include <bits/stdc++.h>

using namespace std;
int in[10002];
int main() {
    memset(in,-1,sizeof(in));
    int n,m,j;
    scanf("%d %d %d",&n,&m,&j);
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        in[a]=b;
    }
    in[n+1]=0;
    deque<int> dq;
//    dq.push_back(0);
    int l=0;
    for(int r=1; r<=n+1; r++){
        if(!dq.empty()&&in[r]!=-1) in[r]=max(in[r],dq.front());
        while(!dq.empty()&&dq.back()>in[r]&&in[r]!=-1)dq.pop_back();
        if(in[r]!=-1)dq.push_back(in[r]);
        while(l<r-j){
            if(dq.empty()){
                printf("-1");
                return 0;
            }
            if(dq.front()==in[l])dq.pop_front();
            l++;
        }
        
    }
    while(l<n+1-j){
        if(dq.empty()){
            printf("-1");
            return 0;
        }
        if(dq.front()==in[l])dq.pop_front();
        l++;
    }
    printf("%d %d",in[n+1],l);
    return 0;
}
