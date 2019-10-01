/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 28, 2019, 2:39 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
float dist(float a,float b, float c, float d){
    return hypot(abs(d-b),abs(c-a));
}
int main() {
    int size;
    scanf("%d",&size);
    float m=0;
    float x[size];
    float y[size];
    for(int i=0; i<size; i++)scanf("%f %f",&x[i],&y[i]);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            for(int k=0; k<size; k++){
                float avX=(x[i]+x[j])/2,avY=(y[i]+y[j])/2;
                m=max(m,dist(avX,avY,x[k],y[k]));
            }
        }
    }
    m=round(m*100)/100.0;
    printf("%.2f",m);

}

