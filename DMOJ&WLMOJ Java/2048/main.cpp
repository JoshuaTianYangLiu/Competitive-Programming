/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 16, 2019, 3:41 p.m.
 */

#include <stdio.h>
#include <math.h>

using namespace std;

/*
 * 
 */
int main() {
    int pow2[31]={0};
    
    int size;
    scanf("%d",&size);
    int in;
    for(int i=0; i<size; i++){
        scanf("%d",&in);
        pow2[(int)(log2(in)-1)]++;
    }
    int max;
    for(int i=0; i<30; i++){
        pow2[i+1]+=pow2[i]/2;
        if(pow2[i+1]>0)max=i+1;
    }
    printf("%d",1<<max+1);
}

