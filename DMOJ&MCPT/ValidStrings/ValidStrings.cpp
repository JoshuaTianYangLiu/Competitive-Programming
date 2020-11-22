#include <bits/stdc++.h>

using namespace std;
char a[1010];
bool b(){
    stack<char> st;
    for(int i=0; i<strlen(a); i++){
        if(a[i]=='('){
            st.push('(');
        }else if(a[i]==')'){
            if(st.empty()){
                return false;
            }else{
                st.pop();
            }
        }
    }
    return st.empty();
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",a);
        printf("%s\n",b()?"YES":"NO");
    }
    return 0;
}