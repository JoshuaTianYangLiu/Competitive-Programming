/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 16, 2019, 12:44 a.m.
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

/*
 * 
 */
int main() {
    char a[1000005], b[1000005];

    scanf("%s",a);
    scanf("%s",b);
    int aL=strlen(a);
    int bL=strlen(b);
    int charSame =0;
    int marker =0;
    for(int i=max(0,aL-bL); i<aL;){
        if(a[i]==b[marker]){
            while(a[i]==b[marker]){
                i++;
                marker++;
                charSame++;
                if(i==aL){ 
                   goto out;
                }
            }
        }
        i++;
        if(i==aL){
            charSame=0;
        }
    }
    out:
    printf("%s",a);
    for(int j=charSame; j<bL; j++){
        printf("%c",b[j]);
    }
    //return 0;
}

