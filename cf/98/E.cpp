#include <bits/stdc++.h>

using namespace std;
char in[200010];
int freq[200010];
bool isVowel(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')return true;
    return false;
}
int main() {
    scanf("%s",in);
    int n=strlen(in);
    for(int i=0; i<n; i++){
        if(isVowel(in[i]))freq[i]++;
        if(i!=0)freq[i]+=freq[i-1];
    }
    for(int l=0; l<n; l++){
        for(int r=l; r<n; r++){
            int v = freq[r]-l==0?0:freq[l-1];
            if(v)
        }
    }
    return 0;
}