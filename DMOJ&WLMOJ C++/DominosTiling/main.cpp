/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 6, 2019, 10:10 a.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int a;
int f(int pos,int line, int taken){
    if(pos==3)return f(0,line+1,taken);
    if(line==a)return 1;
    if((taken&(1<<pos))!=0){
        taken&=~(1<<pos);
        return f(pos+1,line,taken);
    }
    int t=taken;
    int out=0;
    if((taken&(1<<(pos+1)))==0&&(pos==0|pos==1)){
        out+=f(pos+2,line,t);
    }
    if(line+1!=a&&(taken&(1<<pos))==0){
        taken|=1<<pos;
        out+=f(pos+1,line,taken);
    }
  
    return out%1000000;
}
int main() {
    for(int i=0; i<=30; i++){
        a=i;
        printf("%d\n",f(0,0,0));
    }

}

