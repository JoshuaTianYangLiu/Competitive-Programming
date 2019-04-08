/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 20, 2019, 10:17 a.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int size;
    scanf("%d",&size);
    unsigned long long posOut;
    unsigned long long negOut;
    unsigned long long in;
    for(int i=0; i<size; i++){
        scanf("%llu",&in);
        if(in<0){
            negOut=negOut^in;
        }else{
            posOut=posOut^in;
        }
    }
    if(posOut==0){
        printf("%llu\n",negOut);
    }else{
        printf("%llu\n",posOut);
    }
    
}

