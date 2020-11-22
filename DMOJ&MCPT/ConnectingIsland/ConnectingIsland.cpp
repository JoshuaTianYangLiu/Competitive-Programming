/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 8, 2019, 8:25 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
bool isLand[51][51];
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=0; i<a; i++){
        char strip[b];
        scanf("%s",strip);
        for(int j=0; j<b; j++)isLand[i][j]=strip[j]=='X';
    }
    
}

