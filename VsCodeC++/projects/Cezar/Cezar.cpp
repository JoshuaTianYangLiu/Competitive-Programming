#include <bits/stdc++.h>

using namespace std;
string in[101],intemp[101];
vector<int> g[26];
int indeg[26];
char ans[26];
int conv[101];
int main() {
    memset(indeg,0,sizeof(indeg));
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%s\n",&intemp[i]);
    }
    for(int i=1; i<=n; i++){
        int x;
        scanf("%d",&x);
        //Why does this not do what it's suppost to do!
        in[i]=intemp[x];

        printf("%s %s %d\n",in[i],intemp[x],x);
    }
    for(int i=1; i<n; i++){
        
        int pos=0;
        while(in[i][pos]==in[i+1][pos]){
            pos++;
        }
        g[in[i][pos]-'a'].push_back(in[i+1][pos]-'a');
        indeg[in[i+1][pos]-'a']++;
    }
    queue<int> q;
    for(int i=0; i<26; i++){
        if(indeg[i]==0)q.push(i);
    }
    char cnt='a';
    while(!q.empty()){
        int a=q.front();
        ans[a]=cnt++;
        q.pop();
        for(int i=0; i<g[a].size(); i++){
            if(--indeg[g[a][i]]==0)q.push(g[a][i]);
        }

    } 
    if(cnt!='z')printf("NE");
    else printf("DA\n%s",ans);
    return 0;
}