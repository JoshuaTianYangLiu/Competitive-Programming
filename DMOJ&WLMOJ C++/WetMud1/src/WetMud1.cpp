//============================================================================
// Name        : WetMud1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
int in[10002];
int main() {
    memset(in,-1,sizeof(in));
    int n,m,j;
    scanf("%d %d %d",&n,&m,&j);
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        in[a]=b;
    }
    in[n+1]=0;
    deque<int> dq;
//    dq.push_back(0);
    for(int l=0,r=0; r<n; r++){

    	while(!dq.empty()&&dq.back()>in[r]&&in[r]!=-1)dq.pop_back();
    	if(in[r]!=-1)dq.push_back(in[r]);
    	while(l<r-j){

    	}
    }
    if(dq.empty())printf("-1");
    else printf("%d",in[n+1]);
    return 0;
}
