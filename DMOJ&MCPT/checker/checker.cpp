#include <bits/stdc++.h>
using namespace std;
char in[200010];
int n;
pair<int,pair<int,int>> lines[200010];
vector<pair<int,int>> points[200010];
pair<int,pair<int,int>> g[400010];
int pivot=0;
bool f(pair<int,int> a,pair<int,int> b){
    if(a.first>pivot&&b.first>pivot)return a.first>b.first;
    if(a.first<pivot&&b.first<pivot)return a.first>b.first;
    if(a.first>pivot)return false;
    return true;
}
int dist(int a,int b){
    return (n+a-b)%n;
}
bool f1(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return dist(a.second.second,a.second.first)<dist(b.second.second,b.second.first);
}
pair<int,int> convex[200010];
int main() {
    int tmp;
    scanf("%d",&tmp);
    scanf("%d",&n);
    scanf("%s",in);
    for(int i=3; i<n; i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        lines[i-3]={c,{x,y}};
        points[x].push_back({y,i-3});
        points[y].push_back({x,i-3});
        g[2*(i-3)]={c,{x,y}};
        g[2*(i-3)+1]={c,{y,x}};
    }
    sort(g,g+2*(n-3),f1);
    for(int i=1; i<=n; i++){
        pivot=i;
        sort(points[i].begin(),points[i].end(),f);
    }
    stack<int> s;
    // for(int i:points[1])s.push(i);
    int ptr=1;
    while(true){
        for(pair<int,int> i:points[ptr]){
            if(!s.empty()&&i.second==s.top()){
                s.pop();
            }else{
                s.push(i.second);
            }
        }
        ptr=ptr%n+1;
        if(ptr==1)break;
    }
    if(s.size()){
        printf("neispravna triangulacija\n");
        return 0;
    }
    for(int i=1; i<=n; i++){
        convex[i]={i%n+1,in[i-1]-'0'};
    }
    for(int i=0; i<n-2; i++){
        pair<int,pair<int,int>> tmp = g[i];
        // printf("%d %d\n",tmp.second.first,tmp.second.second);
        int a=tmp.first;
        int b=convex[tmp.second.first].second;
        int c=convex[convex[tmp.second.first].first].second;
        // printf("%d %d %d:: %d %d\n",a,b,c,tmp.second.first,convex[tmp.second.first].first);
        if(a+b+c==6&&a!=b&&a!=c&&b!=c){
            convex[tmp.second.first]={tmp.second.second,tmp.first};
        }else{
            printf("neispravno bojenje\n");
            return 0;
        }
    }
    printf("tocno\n");
    return 0;
}