/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 26, 2019, 10:12 p.m.
 */

#include <string>
#include <bits/stdc++.h>


using namespace std;

int size=8;
int conv(int a){
    int out=0;
    int cnt=0;
    for(int i=size-1; i>=0; i--){
        out=out<<1;
        if((a&(1<<i))!=0){
            cnt++;
        }else{
            if(cnt<4&&cnt!=0){
                out+=(1<<cnt)-1;
            }
            cnt=0;
        }
    }
    out=out<<1;
    if(cnt<4&&cnt!=0){
        out+=(1<<cnt)-1;
    }
    return out;
}
int main(){
    for(int j=128; j<160; j++){
        int v=conv(j);
        for (int i = 8; i >= 0; i--){
            printf("%d",(j >> i) & 1);
        }
        printf("\n");
        for (int i = 8; i >= 0; i--){
            printf("%d",(v >> i) & 1);
        }
        printf("\n-----------\n");
    }
}
