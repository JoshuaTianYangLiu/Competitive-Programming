/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 11, 2019, 8:38 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */

char in[201];
bool clos(int s,int e){
    if(in[s]=='?'||in[e]=='?')return true;
    if(in[s]=='('&&in[e]==')')return true;
    if(in[s]=='['&&in[e]==']')return true;
    if(in[s]=='{'&&in[e]=='}')return true;
    return false;
}
int f(int s,int e){
    int tot=0;
    if(e-s==1)return 1;
    if(e-s<1)return 0;
    if(clos(s+1,e-1))tot+=f(s+1,e-1);
    for(int i=s+1; i<e-1; i++){
        if(clos(s,i)&&clos(i+1,e)){
            tot+=f(s,i);
            tot+=f(i+1,e);
        }
    }
    return tot;
}
int main() {
    //Not sure how to do this... sigh
    int size;
    scanf("%d",&size);
    scanf("%s",in);
    printf("%d",f(0,size-1));

}

