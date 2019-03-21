/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 20, 2019, 8:35 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int size;
    scanf("%d",&size);
    unsigned long long total=0;
    
    for(int i=0; i<size; i++){
        long long in;
        scanf("%lld",&in);
        total+=abs(in);
    }
    if(total=0)printf("0");
    else printf("-%llu",total);
}

