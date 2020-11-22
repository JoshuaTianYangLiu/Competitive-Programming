#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        vector<string> lcp;
        char in[5001];
        scanf("%s",in);
        string in2=in;
        int l=strlen(in);
        for(int j=0; j<l; j++) lcp.push_back(in2.substr(j));
        sort(begin(lcp),end(lcp));
        int m=0;
        for(int j=1; j<l; j++){
            int pos=0;
            while(lcp[j-1][pos]==lcp[j][pos]) pos++;
            // printf("%d %s\n",pos,lcp[j-1].c_str());
            m+=pos;
        }
        printf("%d\n",l*(l+1)/2-m+1);
    }
    return 0;
}
