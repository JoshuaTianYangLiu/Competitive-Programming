/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 4, 2019, 2:00 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    //Rip, misread the question
    int size;
    int a[50][50];
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)scanf("%d",&a[j][i]);
    }
    for(int i=size-1;i>=0; i--){
        for(int j=size-1; j>0; j--)printf("%d ",a[i][j]);
        printf("%d\n",a[i][0]);
    }
}

