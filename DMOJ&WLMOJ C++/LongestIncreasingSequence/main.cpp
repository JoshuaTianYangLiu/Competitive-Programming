/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 31, 2019, 11:51 a.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    //This is wrong
    int size;
    scanf("%d",&size);
    int a[size];
    for(int i=0; i<size; i++)scanf("%d",&a[i]);
    int max=0;
    int s=0;
    int sV=a[0];
    for(int i=0; i<size; i++){
        if(a[i]>sV) max=i-s+1;
        else s=i;
        sV=a[i];
    }
    printf("%d\n",max);
}

