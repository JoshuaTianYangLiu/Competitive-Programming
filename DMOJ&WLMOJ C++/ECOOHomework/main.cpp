/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 22, 2019, 8:54 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
pair<int,float> in[1000001];
int main() {
    for(int a=0; a<10; a++){
        int size;
        scanf("%d",&size);
        for(int i=0; i<size; i++){
            int b;
            float c;
            scanf("%d %f",&b,&c);
            in[i]={b,c};
        }
        sort(in,in+size);
        float out=0;
        for(int i=0; i<size; i++){
            if(i==size-1)out+=in[i].second;
            else if(in[i].first!=in[i+1].first)out+=in[i].second;
        }
        printf("%.4f\n",out);
    }

}

