/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 21, 2019, 2:41 p.m.
 */

#include <string>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    float x1,y1,x2,y2,x3,y3;
    int d;
    scanf("%f %f",&x1,&y1);
    scanf("%f %f",&x2,&y2);
    scanf("%f %f",&x3,&y3);
    scanf("$d",&d);
    x1=hypot(abs(x3-x1),abs(y3-y1));
    y1=hypot(abs(x3-x2),abs(y3-y2));
    if(x1<=d||y1<=d)printf("Yes\n");
    else printf("No\n");
    return 0;
}

