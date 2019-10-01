/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 8, 2019, 7:26 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
char in[100001];
int main() {
    scanf("%s",in);
    int l=strlen(in);
    int one=0,zer=0;
    for(int i=0; i<l; i++){
        if(in[i]=='1')one++;
        else zer++; 
    }
    printf("%d",2*min(one,zer));
}

