//apio08p2
#include <bits/stdc++.h>
using namespace std;
struct DisjointSet{
	vector<int> rank,parent;
	int n;
public:
	DisjointSet(int n):n(n), rank(n+1), parent(n+1){}
	void makeSet(){
		for(int i = 0; i<n; i++){
			parent[i] = i;
		}
	}
	int find(int x) { 
	    if (parent[x] != x) { 
	        parent[x] = find(parent[x]); 
	    } 
	    return parent[x]; 
	}
	void Union(int x, int y) { 
	    int xRoot = find(x), yRoot = find(y);  
	    if (xRoot == yRoot) 
	        return; 
	    if (rank[xRoot] < rank[yRoot]) 
	        parent[xRoot] = yRoot; 
	    else if (rank[yRoot] < rank[xRoot]) 
	        parent[yRoot] = xRoot; 
	    else { 
	        parent[yRoot] = xRoot; 
	        rank[xRoot] = rank[xRoot] + 1; 
	    } 
	} 
};
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<pair<int,int>>>adj(n+1);
	map<int,int>hm;
	for(int i = 0; i<m; i++){
		int x,y,w;
		cin >> x >> y >> w;
		adj[x].push_back(make_pair(w,y));
		adj[y].push_back(make_pair(w,x));
		hm[x*30000+y] = 1;
	}
	DisjointSet ds(n);
	ds.makeSet();
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	int cobble = 0;
	vector<pair<int,int>>ans;
	for(int i = 1; i<=n; i++){
		for(pair<int,int>p: adj[i]){
			if(p.second>i)
			q.push(make_pair(p.first,i*30000+p.second));
		}
	}
	for(int i = 0; i<n-1; i++){
		
		while(!q.empty()){
			pair<int,int>p = q.top(); q.pop();
			int cur = p.second/30000;
			int nxt = p.second%30000;
			if(ds.find(cur)==ds.find(nxt)){
				continue;
			}
			if(p.first==0&&cobble==k){
				continue;
			}
			if(p.first==0){
				cobble++;
				ds.Union(cur,nxt);
				ans.push_back(make_pair(p.first,p.second));
				break;
			}
			if(p.first==1){
				ds.Union(cur,nxt);
				ans.push_back(make_pair(p.first,p.second));
				break;
			}
		}
	}
	if(cobble<k){
		cout << "no solution\n";
		return 0;
	}
	for(pair<int,int>p:ans){
		if(hm[p.second]==1)
			cout << p.second/30000 << " " << p.second%30000 << " " << p.first << "\n";
		else{
			cout << p.second%30000 << " " << p.second/30000 << " " << p.first << "\n";
		}
	}
	return 0;
}