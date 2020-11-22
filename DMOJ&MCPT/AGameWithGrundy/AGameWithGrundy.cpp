#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
set<ll> poi;
ll itor[2000100];
map<ll,int> rtoi;
int diff[2000100];
ll freq[1000100];
queue<pair<ll,ll>> ranges;
int main() {
    int n;
    scanf("%d",&n);
    int l,r,y;
    scanf("%d %d %d",&l,&r,&y);
    ll Y=y;
    poi.insert(l);
    poi.insert(r);
    poi.insert(r+1);
    for(int i=0; i<n; i++){
        int x,v,h;
        scanf("%d %d %d",&x,&v,&h);
        ll ri,li;
        if(((h*Y)%v)==0){
            ri = x-1+(Y*h)/v;
            li = x+1-(Y*h)/v;
        }else{
            ri = x+(Y*h)/v;
            li = x-(Y*h)/v;
        }
        poi.insert(ri);
        poi.insert(li);
        poi.insert(ri+1);
        poi.insert(li-1);
        ranges.push({ri,li});
    }
    int id=1;
    for(ll a:poi){
        // printf("::::%lld is %d\n",a,id);
        itor[id]=a;
        rtoi[a]=id++;
    }
    while(ranges.size()){
        pair<ll,ll> a = ranges.front();ranges.pop();
        // printf("::%lld %lld %d %d\n",a.first,a.second,rtoi[a.first],rtoi[a.second]);
        diff[rtoi[a.second]]++;
        diff[rtoi[a.first]+1]--;
    }
    int il = rtoi[l];
    int ir = rtoi[r];
    // printf("::%d %d\n",il,ir);
    for(int i=1; i<id; i++){
        diff[i]+=diff[i-1];
    }
    // for(int i=1; i<id; i++){
    //     printf("%d ",diff[i]);
    // }
    // printf("\n");
    // for(int i=1; i<id; i++){
    //     printf("%lld ",itor[i]);
    // }
    for(int i=il; i<=ir; i++){
        freq[diff[i]]+=itor[i+1]-itor[i];
        // printf("Freq: %d %lld %lld %lld\n",diff[i],itor[i+1],itor[i],itor[i+1]-itor[i]);
    }
    // if(diff[ir-1]==0)freq[0]++;
    for(int i=0; i<=n; i++){
        if(i)freq[i]+=freq[i-1];
        printf("%lld\n",freq[i]);
    }
    return 0;
}