#include <bits/stdc++.h>

using namespace std;

int main() {
    int size,k;
    scanf("%d %d",&size,&k);
    deque<int> mi,ma;
    long answer =0;
    int l =0;
    int x[size+1];
    for(int i=0; i<size; i++){
        scanf("%d",&x[i]);
        while(!ma.empty()&&ma.back()<x[i])ma.pop_back();
        while(!mi.empty()&&mi.back()>x[i])mi.pop_back();
        ma.push_back(x[i]); mi.push_back(x[i]);
        while(ma.front()-mi.front()>k){
            if(ma.front() == x[l]) ma.pop_front();
            if(mi.front() == x[l]) mi.pop_front();
            l++;
        } 
        printf("%d ",i-l+1);
        answer+=i-l+1;
    }
    // printf("%d",answer);
    return 0;
}
