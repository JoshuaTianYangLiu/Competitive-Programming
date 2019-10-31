/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 5, 2019, 9:11 p.m.
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
            return fast_pow_mod((b * b) % mod, x / 2, mod) % mod;

    return (b * fast_pow_mod((b * b) % mod, x / 2, mod) )% mod;
}
int main() {
    unsigned long long n;
    scanf("%llu",&n);
    if(n%2==0){
        n/=2;
        int t=0;
        if(n%4==0)t=1;
        else if(n%4==2)t=-1;
        n=fast_pow_mod(2,n-1,1000000013);
        n*=t;
        unsigned long long m=n*n%1000000013;
        n+=m;
        n%=1000000013;
        printf("%d",n);
    }else{
        n--;
        n/=2;
        int t=1;
        if(n%4==1||n%4==2)t=-1;
        int m=fast_pow_mod(2,2*n-1,1000000013);
        n=fast_pow_mod(2,n-1,1000000013);
        n*=t;
        m+=n;
        m%=1000000013;
        printf("%d",m);
    }

}

