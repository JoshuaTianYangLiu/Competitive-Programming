//============================================================================
// Name        : DiverseArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
int in[1000001];
int freq[1000001];
int main() {
	memset(freq,0,sizeof(freq));
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%d",&in[i]);
	}
//	freq[in[0]]++;
	int cnt=0;
	long long ans=0;
	for(int l=0,r=0; r<n; r++){
		if(freq[in[r]]++==0)cnt++;
		while(cnt>=k){
			ans+=n-r;
			if(--freq[in[l++]]==0)cnt--;
		}
	}
	printf("%lld\n",ans);
    return 0;
}
