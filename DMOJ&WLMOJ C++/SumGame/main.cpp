/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on July 18, 2019, 5:46 p.m.
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int in[100001];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d ",&in[i]);
    int k=0;
    int t=0;
    for(int i=0; i<n; i++){
        int b;
        scanf("%d",&b);
        t+=in[i]-b;
        if(t==0)k=i+1;
    }
    printf("%d",k);
}