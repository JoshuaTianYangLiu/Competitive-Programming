/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 27, 2019, 9:07 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int size;
int a[101];
bool f(int bin){
    if(__builtin_popcount(a)+1==size)return calc(bin);
    bool dec=true,inc=true;
    for(int i=1; i<size; i++){
        if(a[i-1]<a[i])dec=false;
        if(a[i-1]>a[i])inc=false;
    }
    if(dec&&inc)return calc(bin);
    bool out=false;
    for(int i=0; i<size; i++){
        out|=f(bin|(1<<i));
    }
    return !out;
}
//False means A wins
bool calc(int bin){
    if(__builtin_popcount(a)%2==0)return false;
    else return true;
}
int main() {
    //This question is a doozy, do not do it
    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            scanf("%d",&size);
            for(int k=0; k<size; k++){
                scanf("%d",&a[i]);
            }
            printf("%c",f(0)?'B':'A');
        }
    }

}

