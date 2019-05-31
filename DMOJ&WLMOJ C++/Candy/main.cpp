/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 15, 2019, 2:35 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
pair<int,int> in[101];
bool m[5000000];
int numM[5000000];
int main() {
    int n;
    int tot=0;
    scanf("%d",&n);
    memset(m,false,sizeof(m));
    for(int i=0; i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        tot+=a*b;
        in[i]={a,b};
        
    }
    int out1=tot;
    tot/=2;
    m[0]=true;
    int out=0;
    for(int i=0; i<n; i++){
        memset(numM,0,sizeof(numM));
        for(int j=0; j<=tot; j++){
            if(!m[j+in[i].second]&&m[j]&&numM[j]!=in[i].first&&j+in[i].second<=tot){
                m[j+in[i].second]=true;
                numM[j+in[i].second]=numM[j]+1;
                out=max(out,j+in[i].second);
            }
        }
    }

    printf("%d",out1-2*out);

}

