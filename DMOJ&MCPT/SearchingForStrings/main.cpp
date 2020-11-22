#include <bits/stdc++.h>

using namespace std;
int cnt[26];
int aCnt[26];
char a[200020],b[200020],subStr[200020];
bool sameString(){
    for(int i=0; i<26; i++){
        // printf("%d ",cnt[i]);
        if(aCnt[i]!=cnt[i]){
            // printf("\n");
            return false;
        }
    }
    // printf("\n");
    return true;
}
int main(){
    set<long long> um;
    // printf("%d",um.max_size());
    scanf("%s",a);
    scanf("%s",b);
    int al=strlen(a),bl=strlen(b);
    for(int i=0; i<al; i++)aCnt[a[i]-'a']++;
    for(int i=0; i<bl; i++){
        // printf("::%d\n",i);
        cnt[b[i]-'a']++;
        if(i>=al)cnt[b[i-al]-'a']--;
        if(i>=al-1){
            if(sameString()){
                memset(subStr,0,sizeof(subStr));
                strncpy(subStr,b+i-al+1,al);
                // printf("%s\n",subStr);
                //Test distictness
                um.insert(hash<string>{}(subStr));
            }
        }
    }
    // printf("%d\n",bl);
    printf("%d\n",um.size());
    return 0;
}