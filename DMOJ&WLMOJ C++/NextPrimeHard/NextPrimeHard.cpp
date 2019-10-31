/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 5, 2019, 5:18 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
unsigned long long fast_pow_mod(unsigned long long b, unsigned long long x, unsigned long long mod) {
    if (x == 0)
            return 1;
    if (x == 1)
            return b;
    if (x % 2 == 0)
            return fast_pow_mod(b * b % mod, x / 2, mod) % mod;

    return b * fast_pow_mod(b * b % mod, x / 2, mod) % mod;
}
bool probPrime(unsigned long long a,unsigned long long t){
    unsigned long long r =rand()% (a -1) + 1;
    unsigned long long p=fast_pow_mod(r,t,a);
    if(p==1||p==a-1)return true;
    unsigned long long d=t;
    while(t!=a- 1&&p!=1 & p!=a -1){
        p=(p%a*p%a)%a;
        d*=2;
    }
    return false; 
    
}
bool isPrime(unsigned long long n){
    if(n<1||n==4)return false;
    if(n<=3)return true;
    unsigned long long t=n-1;
    while(t%2==0)t/=2;
    if(!probPrime(n,t))return false;
    return true;
}
int main() {
    unsigned long long size;
    scanf("%lld",&size);
    while(true){
        if(isPrime(size)){
            printf("%lld",size);
            return 0;
        }
        size++;
//        printf("%lld\n",size);
    }

}

