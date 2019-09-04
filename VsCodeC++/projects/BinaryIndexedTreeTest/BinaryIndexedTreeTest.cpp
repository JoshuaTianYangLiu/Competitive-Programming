#include <bits/stdc++.h>

using namespace std;
pair<int,long long> ft[100001];
//freq sum
int n,m;
int arr[100001];
void update(int v,int ind,int opt){
	//i+=i&-i
	//i-=i&-i
	if(opt==1){
		while(v<=100000){
			ft[v].first+=ind;
			v+=v&-v;
		}
	}else{
		while(ind<=100000){
			ft[ind].second+=v;
			ind+=ind&-ind;
		}
	}
}
long long rfq(int v){
	long long sum=0;
	while(v){
		sum+=ft[v].first;
		v-=v&-v;
	}
	return sum;
}
long long rsq(int v){
	long long sum=0;
	while(v){
		sum+=ft[v].second;
		v-=v&-v;
	}
	return sum;
}
long long query(int l,int r,int opt){
	// sub v
	if(opt==1){
		return rfq(l);
	}else{
		return rsq(r)-rsq(l-1);
	}
}
int main() {
	memset(arr,0,sizeof(arr));
	memset(ft,0,sizeof(ft));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n; i++){
		scanf("%d",&arr[i]);
	}
	for(int i=1; i<=n; i++){
		//freq
		update(arr[i],1,1);
		//sum
		update(arr[i],i,2);
	}
	for(int i=0; i<m; i++){
		char option;
		scanf("\n%c ",&option);
		if(option=='C'){
			int a,b;
			scanf("%d %d",&a,&b);
			update(b-arr[a],a,2);
			update(arr[a],-1,1);
			arr[a]=b;
			update(arr[a],1,1);
		}else if(option=='S'){
			int l,r;
			scanf("%d %d",&l,&r);
			printf("%lld\n",query(l,r,2));
		}else if(option=='Q'){
			int x;
			scanf("%d",&x);
			printf("%lld\n",query(x,1,1));
		}
	}
    return 0;
}
