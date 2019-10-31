/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 29, 2019, 5:28 p.m.
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
    bool t[a*b+1];
    memset(t,true,sizeof(t));
    for(int i=0; i<a*b; i+=b){
        t[i]=false;
    }
    int out=0;
    for(int i=0; i<a*b; i+=a){
        if(t[i])out++;
    }
    printf("%d",out);
}

