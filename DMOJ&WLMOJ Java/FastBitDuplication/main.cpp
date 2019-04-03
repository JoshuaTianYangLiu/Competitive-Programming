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
    unsigned long long b;
    while(a){
        if(a>>1==1){
            b<<1;
            b++;
            b<<1;
            b++;
        }else b<<2;
        a=a>>1;
    }
    unsigned long long count = sizeof(b) * 64 - 1; 
    unsigned long long reverseNum = b; 
      
    b >>= 1;  
    while(b) 
    { 
       reverseNum <<= 1;        
       reverseNum |= b & 1; 
       b >>= 1; 
       count--; 
    } 
    reverseNum <<= count; 
    return reverseNum;
}
int main() {
    for(;;){
        unsigned long long a;
        scanf("%llu",&a);
        printf("%llu\n",duplicatebits(a));
    }
}

