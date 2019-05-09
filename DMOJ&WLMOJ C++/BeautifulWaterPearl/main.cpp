/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 14, 2019, 7:42 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int c;
    int d;
    int e;
    scanf("%d %d %d",&c,&d,&e);
    int size=log2(c)+1;
    int total=0;
    while(c){
        if((c&1)&&!(d&1)){
            if(!(e&1)){
                printf("0");
                return 0;
            }
            total=total==0?2:total*2;
        }
        c=c>>1;
        d=d>>1;
        e=e>>1;
        
        
    }
    printf("%d",total);
}

