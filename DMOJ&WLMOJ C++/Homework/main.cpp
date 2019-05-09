/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 26, 2019, 6:25 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int cnt[10000001];
int main() {
    memset(cnt,-1,sizeof(cnt));
    for(int i=2; i<10000001; i++){
        if(cnt[i]==-1){
            for(int j=i; j<10000001; j+=i){
                cnt[j]=cnt[j]==-1?1:cnt[j]+1;
            }
        }
    }
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int out=0;
        for(int j=a; j<=b; j++){
            if(cnt[j]==c){
                out++;
            }
        }
        printf("Case #%d: %d\n",i,out);
    }

}

