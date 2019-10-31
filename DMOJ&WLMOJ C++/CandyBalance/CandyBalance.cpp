/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on June 8, 2019, 7:20 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int in[10001];
int main() {
    int size;
    scanf("%d",&size);
    int tot=0;
    for(int i=0; i<size; i++){
        scanf("%d",&in[i]);
        tot+=in[i];
        
    }
    tot/=size;
    int ans=0;
    for(int i=0; i<size; i++){
        if(tot>in[i]){
            
            ans+=tot-in[i];
        }
        
    }
    printf("%d",ans);
}

