#include <bits/stdc++.h>

using namespace std;
set<int> xVal,yVal;
struct coords{int a,b,c,d,e;};
vector<coords> coord;
map<int,int> xtoi,ytoi;
vector<long long> itox,itoy;
int compressedGrid[2020][2020];
int main() {
	int n,k;
	scanf("%d",&n);
	for(int i=0,a,b,c,d; i<n; i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		coord.push_back({a,d,c,b,1});
		xVal.insert(a);
		xVal.insert(c);
		yVal.insert(b);
		yVal.insert(d);
	}
	int cnt=0;
	for(int t:xVal){
		xtoi[t]=cnt++;itox.push_back(t);
	}
	cnt=0;
	for(int t:yVal){
		ytoi[t]=cnt++;itoy.push_back(t);
	}
	for(coords c:coord){
		compressedGrid[xtoi[c.a]][ytoi[c.b]]+=c.e;
		compressedGrid[xtoi[c.c]][ytoi[c.d]]+=c.e;
		compressedGrid[xtoi[c.a]][ytoi[c.d]]-=c.e;
		compressedGrid[xtoi[c.c]][ytoi[c.b]]-=c.e;
		// printf("%d %d %d %d %d\n",xtoi[c.a],ytoi[c.b],xtoi[c.c],ytoi[c.d],c.e);
	}
	
	for(int i=1; i<xtoi.size(); i++){
		for(int j=0; j<ytoi.size(); j++){
			compressedGrid[i][j]+=compressedGrid[i-1][j];
		}
	}
	for(int i=0; i<xtoi.size(); i++){
		for(int j=1; j<ytoi.size(); j++){
			compressedGrid[i][j]+=compressedGrid[i][j-1];
		}
	}
	// for(int j=0; j<=ytoi.size()+2; j++){
	// 	for(int i=0; i<=xtoi.size()+2; i++){
	// 		printf("%d ",compressedGrid[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	long long ans=0;
	for(int i=0; i<xtoi.size()-1; i++){
		for(int j=0; j<ytoi.size()-1; j++){
			if(compressedGrid[i][j]>0){
				ans+=(itox[i+1]-itox[i])*(itoy[j+1]-itoy[j]);
				// printf("%d %d %d %d\n",itox[i+1],itox[i],itoy[j+1],itoy[j]);
			}
		}
	}
	printf("%lld\n",ans);
    return 0;
}