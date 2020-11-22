/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 23, 2019, 10:31 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    int i=0;
    int cnt=0;
    while(pow(i,6)<a)i++;
    while(pow(i,6)<=b){
        cnt++;
        i++;
    }
    printf("%d",cnt);
}

