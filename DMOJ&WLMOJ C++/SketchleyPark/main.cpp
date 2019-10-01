/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on May 11, 2019, 2:53 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
char cryp[100001];
char st[500001][26];
int main() {
    scanf("%s",cryp);
    int len=strlen(cryp);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",st[i]);
    }
    char h,a,b,l,y,d,r;
    for(int i=0; i<len-8; i++){
        if(cryp[i]==cryp[i+4]&&cryp[i+1]==cryp[i+8]&&
                cryp[i]!=cryp[i+1]&&cryp[i]!=cryp[i+2]&&cryp[i]!=cryp[i+3]&&cryp[i]!=cryp[i+5]&&cryp[i]!=cryp[i+6]&&cryp[i]!=cryp[i+7]&&
                cryp[i+1]!=cryp[i+2]&&cryp[i+1]!=cryp[i+3]&&cryp[i+1]!=cryp[i+5]&&cryp[i+1]!=cryp[i+6]&&cryp[i+1]!=cryp[i+7]&&
                cryp[i+2]!=cryp[i+3]&&cryp[i+2]!=cryp[i+5]&&cryp[i+2]!=cryp[i+6]&&cryp[i+2]!=cryp[i+7]&&
                cryp[i+3]!=cryp[i+5]&&cryp[i+3]!=cryp[i+6]&&cryp[i+3]!=cryp[i+7]&&
                cryp[i+5]!=cryp[i+6]&&cryp[i+5]!=cryp[i+7]&&
                cryp[i+6]!=cryp[i+7]){
            //HailHydra
            h=cryp[i];
            a=cryp[i+1];
            b=cryp[i+2];
            l=cryp[i+3];
            y=cryp[i+5];
            d=cryp[i+6];
            r=cryp[i+7];
            for(int z=0; z<n; z++){
                if(st[z][7]==h&&st[z][0]==a&&st[z][8]==b&&st[z][11]==l&&st[z][24]==y&&st[z][3]==d&&st[z][17]==r){
                    char covKey[26];
                    for(int j=0; j<26; j++){
                        covKey[st[z][j]-'A']=j+'A';
                    }
                    for(int j=0;j<len; j++){
                        printf("%c",covKey[cryp[j]-'A']);
                    }
                    return 0;
                }
            }
        }
    }
//    printf("HAILHYDRA\n%c%c%c%c%c%c%c%c%c",h,a,b,l,h,y,d,r,a);
    printf("KeyNotFoundError");
}

