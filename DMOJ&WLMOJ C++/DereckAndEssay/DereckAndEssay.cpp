/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 17, 2019, 10:09 p.m.
 */

#include <string.h>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

/*
 * 
 */

int main() {
    //THIS IS ALL WRONG AND I DO NOT KNOW WHY
    char a[2005];
    char b[2005];
    scanf("%s",a);
    int aL = strlen(a);
    int st=0,en;
    for(int i=0; i<aL; i++){
        if(a[i]==' '||i==aL-1){
            if(i!=aL-1)strcat(b," ");
            for(int j=i-1; j>=st; j--){
                strcat(b,a[j]+"");
            }
            st=i+1;
        }
    }
    printf("%s",b);
}

