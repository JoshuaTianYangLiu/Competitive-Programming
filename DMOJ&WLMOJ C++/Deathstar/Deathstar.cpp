/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 15, 2019, 12:03 a.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int a;
    scanf("%d",&a);
    int out[a];
    memset(out,0,sizeof(out));
    int b;
    for(int i=0; i<a-1; i++){
        for(int j=0; j<=i; j++)scanf("%d",&b);
        for(int j=i+1; j<a; j++){
            scanf("%d",&b);
            out[i]|=b;
            out[j]|=b;
        }
    }
    for(int i=0; i<a; i++) printf("%d ",out[i]);
}

