/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 31, 2019, 12:20 p.m.
 */

#include <string>
#include <bits/stdc++.h>
#define MM 1000000007
using namespace std;

/*
 * 
 */
long long* mul(long long n[],long long m[]){
    long long a=((n[0]*m[0])%MM+(n[1]*m[2])%MM)%MM;
    long long b=((n[0]*m[1])%MM+(n[0]*m[3])%MM)%MM;
    long long c=((n[2]*m[0])%MM+(n[3]*m[2])%MM)%MM;
    long long d=((n[2]*m[1])%MM+(n[3]*m[3])%MM)%MM;
    long long e[]={a,b,c,d};
    return e;
}
long long def[]={1,1,1,1};
long long* fast_pow_mod(long long b[], unsigned long long x) {
    if (x == 0)return def;
    if (x == 1)return b;
    if (x % 2 == 0)return fast_pow_mod(mul(b,b), x / 2);
    return mul(b,fast_pow_mod(mul(b,b), x / 2));
}
int main(){
    unsigned long long n;
    scanf("%llu",&n);
    long long t[]={0,1,1,1};
    long long* a=fast_pow_mod(t,n);
    for(int i=0; i<4; i++)printf("%lld ",a[i]);
}

