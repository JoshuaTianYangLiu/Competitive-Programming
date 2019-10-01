/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 18, 2019, 10:59 a.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int n;
    srand(time(NULL));
    n=rand()%10;
    printf("%d\n",n);
    for(int i=0; i<n; i++)printf("%d",rand()%2);
    printf("\n");
    for(int i=0; i<n; i++)printf("%d",rand()%2);
}

