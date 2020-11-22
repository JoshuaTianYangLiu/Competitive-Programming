/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 20, 2019, 8:54 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int gcd (int a, int b) {
    return b == 0 ? a : gcd (b, a % b);
}
int main() {
    int size;
    scanf("%d",&size);
    int a;
    scanf("%d",&a);
    int in;
    int gc;
    for(int i=1; i<size; i++){
        scanf("%d",&in);
        gc = gcd(a,in);
        printf("%d/%d\n",a/gc,in/gc);
    }
}


