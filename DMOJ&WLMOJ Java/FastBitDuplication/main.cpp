/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 24, 2019, 12:46 a.m.
 */


#include <bits/stdc++.h>
#include <stack>
using namespace std;

/*
 * 
 */
unsigned long long duplicatebits(unsigned long long a){
    unsigned long long out=0;
    for(int i=31; i>=0; i--){
        out=out<<2;
        out+=a&(1<<i)?3:0;
    }
    return out;
}
int main() {
    for(;;){
        unsigned long long a;
        scanf("%llu",&a);
        printf("%llu\n",duplicatebits(a));
    }
}

