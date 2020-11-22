/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 16, 2019, 4:09 p.m.
 */

#include <stdio.h>
#include <math.h>

using namespace std;

/*
 * 
 */
int main() {
    int h;
    int m;
    int temp;
    scanf("%d%d",&h,&m);
    scanf("%d",&temp);
    m+=temp;
    h+=m/60;
    m%=60;
    h%=24;
    printf("%d %d",h,m);
}

