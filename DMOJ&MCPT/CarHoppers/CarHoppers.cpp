/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 1, 2019, 7:26 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    for(int a=0; a<5; a++){
        int size,dist;
        scanf("%d %d",&size, &dist);
        int car[size];
        for(int i=0; i<size; i++)scanf("%d",&car[i]);
        int pos=0;
        int tot=0;
        int cur=0;
        for(int i=0; i<size;){
            cur=i;
            for(int j=cur;j<i+dist&&j<size; j++){
                if(car[j]>car[cur])cur=j;
            }
            tot++;
            for()
        }
    }

}

