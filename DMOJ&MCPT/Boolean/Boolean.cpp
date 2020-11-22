/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 23, 2019, 8:28 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    char a[1000];
    scanf("%[^\n]",a);
    int b = strlen(a);
    if(b%8==4)printf("True");
    else if(b%8==5)printf("False");
    else if(b%8==0)printf("False");
    else if(b%8==1)printf("True");
}

