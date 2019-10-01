/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 14, 2019, 7:06 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int size;
    scanf("%d",&size);
    int a[size];
    int b[size];
    for(int i=0; i<size; i++)scanf("%d %d",&a[i],&b[i]);
    int min=INT_MAX;
    for(int i=1; i<1<<size; i++){
        int c=1;
        int d=0;
        for(int j=0; j<size; j++){
            int e=i&1<<j;
            if(e!=0){
                c*=a[j];
                d+=b[j];
            }
        }
        min=abs(c-d)<min?abs(c-d):min;
    }
    printf("%d",min);

}

