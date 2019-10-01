/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 21, 2019, 2:57 p.m.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
long in[200002];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++){
        scanf("%ld",&in[i]);
        in[i+n]=in[i];
    }
    deque<long> dq;
    long m=-10000000000;
    dq.push_back(0);
    for(int j=0,i=1; i<2*n; i++){
        in[i]+=in[i-1];
        while(!dq.empty()&&dq.back()>in[i])dq.pop_back();
        dq.push_back(in[i]);
        while(j<i-k){
            if(dq.front()==in[j])dq.pop_front();
            j++;
        }
        m=max(m,in[i]-dq.front());
    }
    printf("%ld",m);
}