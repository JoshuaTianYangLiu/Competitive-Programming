// Problem : Kevin Needs Help
// Contest : DMOJ
// URL : https://dmoj.ca/problem/kevin
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int par[1000005], wt[1000005], dep[1000005];
vector<pair<int, int>> graph[1000005];
int qu[2][1000005];

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))


void dfs(int n){
	for(auto e : graph[n]){
		if(e.first != par[n]){
			par[e.first] = n;
			wt[e.first] = e.second;
			dep[e.first] = dep[n] + 1;
			dfs(e.first);
		}
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]){
		swap(x, y);
	}
	while(dep[x] != dep[y]){
		x = par[x];
	}
	while(x != y){
		x = par[x];
		y = par[y];
	}
	return x;
}

int build(int x, int y, int t){
	int p = lca(x, y);
	int d = dep[x] + dep[y] - 2*dep[p];
	int idx = 0;
	while(x != p){
		qu[t][++idx] = wt[x];
		x = par[x];
	}
	idx = d;
	while(y != p){
		qu[t][idx--] = wt[y];
		y = par[y];
	}
	return d;
}

int main(){
    time__("Solve"){
        freopen("data.in","r",stdin);
        // ios::sync_with_stdio(0);
        // cin.tie(0);
        // cout.tie(0);
        freopen("aqt.out","w",stdout);
        scanf("%d %d",&N,&Q);
        for(int i = 1; i<N; i++){
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            graph[a].emplace_back(b, c);
            graph[b].emplace_back(a, c);
        }
        dfs(1);
        while(Q--){
            int a, b, x, y;
            scanf("%d %d %d %d",&a,&b,&x,&y);
            int l1 = build(a, b, 0);
            int l2 = build(x, y, 1);
            if(l1 != l2){
                cout << "F\n";
                printf("Ree\n");
            }
            else{
                bool bb = 1;
                for(int i = 1; i<=l1; i++){
                    if(qu[0][i] != qu[1][i]){
                        bb = 0;
                        break;
                    }
                }
                cout << (bb ? "T" : "F") << "\n";
            }
        }
        fclose(stdout);
        fclose(stdin);
    }
}
