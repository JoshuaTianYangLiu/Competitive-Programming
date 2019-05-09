/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on April 24, 2019, 7:24 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int dp[901];
string l[10]={"ook","ook ook","oog","ooga","ug","mook","mook mook","oogam","oogum","ug ug"};
int f(string a, int s){
    if(s>=a.size())return 0;
    if(dp[s]!=-1)return dp[s];
    int b=0;
    for(int i=0; i<10; i++){
        if(a.find(s,l[i].size()+s)==l[i]){
            b+=f(a,l[i].size()+s)+1;
        }
    }
    dp[s]=b;
    return b;
}
int main() {
    //strings are annoying
    for(int i=0; i<10; i++){
        string a;
        getline(cin,a);
        memset(dp,-1,sizeof(dp));
        printf("%d",f(a,0));
    }

}

