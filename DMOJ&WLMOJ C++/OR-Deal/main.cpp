/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 14, 2019, 6:47 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    unsigned long long a;
    scanf("%llu",&a);
    int s=log2(a)+1;
    for(int i=0; i<s; i++)printf("1");
}

