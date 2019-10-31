/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 31, 2019, 7:42 p.m.
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    int size;
    scanf("%d",&size);
    long long k;
    scanf("%lld",&k);
    long long total=0;
    long long min=-1;
    int a[size];
    for(int i=0; i<size; i++)scanf("%d",&a[i]);
    int s=0;
    int i=0;
    while(i<size){
        if(total>=k){
            if(min==-1||i-s<min)min=i-s;
            total-=a[s];
            s++;
        }else{
            total+=a[i];
            i++;
        }
    }
    while(total>=k){
        if(min==-1||i-s<min)min=i-s;
        total-=a[s];
        s++;
    }
    printf("%lld",min);

}

