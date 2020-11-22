/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 5, 2019, 7:07 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int size=log2(a-1)+1;
    int totOne=0;
    for(int i=0; i<a; i++){
        totOne+=__builtin_popcount(i);
    }
    size*=a;
    printf("%d",b*(size-totOne)+c*totOne);
}

