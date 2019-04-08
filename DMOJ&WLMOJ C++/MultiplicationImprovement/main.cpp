/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 4, 2019, 10:24 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    //Not working
    char in[39];
    scanf("%s",in);
    int a=strlen(in);
    int b[20];
    for(int i=1; i<a; i+=2)b[(i-1)/2]=in[i]-'0';
    sort(b,(a-b)/2+1);
    for(int i=1; i<(a-1)/2; i++)printf("%dx",b[i]);
    printf("%d\n",b[(a-1)/2]);
}

