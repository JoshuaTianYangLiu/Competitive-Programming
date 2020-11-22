#include <bits/stdc++.h>

using namespace std;
#define MM 1000010
#define SOL 299792458
int beaconLoc[1010];
pair<double,int> times[2020];
int pos[1010];
vector<pair<int,pair<int,int>>> lengths;
int search(int n){
    int l=0,r=lengths.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(lengths[m].first>n)r=m-1;
        else if(lengths[m].first<n)l=m+1;
        else return m;
    }
    return -1;
}
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%d",&beaconLoc[i]);
    }
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++)lengths.push_back({beaconLoc[j]-beaconLoc[i],{beaconLoc[i],beaconLoc[j]}});
    }
    sort(begin(lengths),end(lengths));
    for(int i=0; i<2*k; i++){
        double a;
        scanf("%lf",&a);
        times[i]={a,(int)round(SOL*(ceil(a)-a))};
    }
    sort(begin(times),begin(times)+2*k);
    for(int i=0; i<2*k; i++){
        printf("::%d\n",times[i].second);
    }
    int pos=search(times[0].second+times[1].second);
    if(pos==-1)pos=search(abs(times[1].second-times[0].second));
    int start = lengths[pos].second.first+times[0].second;
    int pos1=search(times[2].second+times[3].second);
    int speed = lengths[pos].second.first+times[2].second-start;
    printf("::%d\n",pos1);
    printf("%d %d",start,speed);
    return 0;
}