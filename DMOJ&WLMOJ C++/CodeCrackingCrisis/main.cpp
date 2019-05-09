/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 25, 2019, 4:23 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    char key[10][10];
    for(int i=0; i<10; i++)scanf("%s",&key[i][0]);
    char e[1000001];
    scanf("%s",&e);
    int size=strlen(e);
    int k=e[0]-'0';
    printf("%d",k);
    for(int i=1; i<size; i++){
        int t=e[i]-'0';
        for(int j=0; j<10; j++){
            if(key[k][j]-'0'==t){
                k=j;
                break;
            }
        }
        printf("%d",k);
    }
}

