#include <bits/stdc++.h>

using namespace std;
int in[1001][1001];
int h[1001];
int main() {
    memset(h,0,sizeof(h));
    int r,s;
    scanf("%d %d",&r,&s);
    for(int i=0; i<r; i++){
        for(int j=0; j<s; j++){
            scanf("%d",&in[i][j]);
        }
    }
    int ans=0;
    for(int i=0; i<r-1; i++){
        for(int j=0; j<s-1; j++){
            if(in[i][j]+in[i+1][j+1]<=in[i+1][j]+in[i][j+1]) h[j]++;
            else h[j]=0;
        }
        stack<int> st;
        int area=0;
        for(int k=0; k<s; k++){
            while(!st.empty()&&h[k]<=h[st.top()]){
                int pos=st.top(); st.pop();
                int prev=st.empty()?0:st.top()+1;
                area=max(area,(h[pos]+1)*(k-prev+1));
            }
            st.push(k);
        }
        ans=max(ans,area);
    }
    printf("%d",ans);
    return 0;
}