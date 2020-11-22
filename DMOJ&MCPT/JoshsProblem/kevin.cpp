#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>lvl(100001);
map<pair<int,int>,int>hm;
int ln = 20; int seed = 131;
int n,q;
int mod = (int)1e9+7;
vector<vector<int>>dp(100001,vector<int>(20));
vector<vector<int>>hash1(100001,vector<int>(20));//up hash
vector<vector<int>>hash2(100001,vector<int>(20));//down hash
vector<vector<int>>adj(100001);
vector<int>powers(2000001);
void dfs(int u, int v){
	lvl[u] = lvl[v]+1;
	dp[u][0] = v; hash1[u][0] = hm[{u,v}]; hash2[u][0] = hm[{u,v}];
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
		hash1[u][i] = hash1[u][i-1]*powers[(1<<(i-1))] + hash1[dp[u][i-1]][i-1];hash1[u][i]%=mod;
		hash2[u][i] = hash2[u][i-1] + hash2[dp[u][i-1]][i-1]*powers[(1<<(i-1))];hash2[u][i]%=mod;
	}
	for(int nxt: adj[u]){
		if(nxt!=v){
			dfs(nxt,u);
		}
	}
}
int lca(int u, int v){
	if(lvl[u]<lvl[v]){
		int diff = lvl[v]-lvl[u];
		int cur = 0;
		int hsh = 0;
		for(int i = 0; i<ln; i++){
			if(diff&(1<<i)){
				int temp = dp[v][i];
				hsh = hash2[v][i]*powers[cur] + hsh;
				hsh%=mod;
				cur+=(1<<i);
				v = temp;
			}
		}
		if(v==u)return hsh;
		int len = 0; int hsh1 = 0; int hsh2 = 0;
		for(int i = ln-1; i>=0; i--){
			if(dp[u][i]!=dp[v][i]){
				int temp1 = dp[u][i]; int temp2 = dp[v][i];
				hsh1 = hsh1*powers[(1<<i)]+hash1[u][i];hsh1%=mod;
				hsh2 = hash2[v][i]*powers[len]+hsh2;hsh2%=mod;
				len+=(1<<i);
				u = temp1; v = temp2;
			}
		}
		hsh1 = hsh1*seed+hash1[u][0];hsh1%=mod;
		hsh2 = hash2[v][0]*powers[len]+hsh2;hsh2%=mod;
		len++;
		hsh1 = hsh1*powers[len] + hsh2;hsh1%=mod;
		hsh1 = hsh1*powers[cur] + hsh;hsh1%=mod;
		return hsh1;
	}
	else{
		int diff = lvl[u]-lvl[v];
		int cur = 0;
		int hsh = 0;
		for(int i = 0; i<ln; i++){
			if(diff&(1<<i)){
				int temp = dp[u][i];
				hsh = hsh*powers[(1<<i)] + hash1[u][i];hsh%=mod;
				cur+=(1<<i);
				u = temp; 
			}
		}
		if(v==u){
			return hsh;
		}
		int len = 0; int hsh1 = 0; int hsh2 = 0;
		for(int i = ln-1; i>=0; i--){
			if(dp[u][i]!=dp[v][i]){
				int temp1 = dp[u][i]; int temp2 = dp[v][i];
				hsh1 = hsh1*powers[(1<<i)]+hash1[u][i];hsh1%=mod;
				hsh2 = hash2[v][i]*powers[len]+hsh2;hsh2%=mod;
				len+=(1<<i);
				u = temp1; v = temp2;
			}
		}
		hsh1 = hsh1*seed+hash1[u][0];hsh1%=mod;
		hsh2 = hash2[v][0]*powers[len]+hsh2;hsh2%=mod;
		len++;
		hsh = hsh*powers[len]+hsh1;hsh%=mod;
		hsh = hsh*powers[len]+hsh2;hsh%=mod;
		return hsh;
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	powers[0] = 1;
	for(int i = 1; i<=2000000; i++){
		powers[i] = powers[i-1]*seed;
	}
	for(int i = 0; i<n-1; i++){
		int x,y,w;
		cin >> x >> y >> w;
		adj[x].push_back(y);
		adj[y].push_back(x);
		hm[{x,y}] = w; hm[{y,x}] = w;
	}
	dfs(1,0);
	while(q--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(lca(a,b)==lca(c,d)){
			cout << "T\n";
		}
		else{
			cout << "F\n";
		}
	}
	return 0;
}