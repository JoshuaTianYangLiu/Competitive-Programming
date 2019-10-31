/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 17, 2019, 4:43 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int t;
    scanf("%d ",&t);
    char a;
    int b;
    while(true){
        scanf("%c",&a);
        if(a=='=')break;
        scanf("%d ",&b);
        t=a=='P'?t+b:t-b;
    }
    printf("%d",t);
}

