/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 4, 2019, 12:55 p.m.
 */


#include <queue>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main() {
    //Does not work
    char in[10000];
    scanf("%s",in);
    char key[10000];
    scanf("%s",key);
    queue<char> q;
    int kL=strlen(key);
    int iL=strlen(in);
    char out[10000];
    for(int i=0; i<kL; i++)q.push(key[i]);
    for(int i=0; i<iL; i++){
        int a = in[i]-(q.front()-65);
        a=a<65?a+26:a;
        out[i]=(char)a;
        q.push(out[i]);
        q.pop();
    }
    printf("%s\n",out);
}

