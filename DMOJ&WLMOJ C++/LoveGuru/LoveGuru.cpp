/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 31, 2019, 8:07 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int calc(int a,int pos){
    pos%=4;
    pos++;
    a%=10;
    int out=1;
    for(int i=0; i<pos; i++){
        out*=a;
        out%=10;
    }
    return out;
}
int main() {
    char a[1000000];
    char b[1000000];
    scanf("%s",a);
    scanf("%s",b);
    int aS=strlen(a);
    int bS=strlen(b);
    int aTotal=0;
    int bTotal=0;
    for(int i=0; i<aS; i++){
        if(a[i]>96)aTotal+=calc(a[i]-96,i);
        else aTotal+=calc(a[i]-64,i);
    }
    aTotal--;
    aTotal%=10;
    aTotal++;
    for(int i=0; i<bS; i++){
        if(b[i]>96)bTotal+=calc(b[i]-96,i);
        else bTotal+=calc(b[i]-64,i);
    }
    bTotal--;
    bTotal%=10;
    bTotal++;
    printf("%d",aTotal+bTotal);
}

