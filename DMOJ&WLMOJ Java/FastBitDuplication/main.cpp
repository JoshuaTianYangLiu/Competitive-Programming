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
unsigned long long duplicatebits(unsigned long long b){
    char s[100];
    sprintf(s, "%b", b);
    strcpy(s,"101");
    unsigned long long c = strtoull(s,NULL,4 );
    return c*3;
}
int main() {
    for(;;){
        unsigned long long a;
        scanf("%llu",&a);
        printf("%llu\n",duplicatebits(a));
    }
}

