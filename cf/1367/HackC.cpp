///***  Black.Ace  ***///
// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
#define input freopen("input.txt", "r", stdin);
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
///***  Black.Ace  ***///

 
#include<bits/stdc++.h>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

int main()
{
    
    time__("Solve"){
        freopen("data.in","r",stdin);
        // freopen("data.out","w",stdout);
        fio
        int t;
        cin>>t;
        cout<<t;
        while(t--){
            string s;
            int n, k, ans=0;
            cout<<"Test"<<endl;
            cin>>n>>k>>s;
            string txt, pat, st;
            for(int i=1; i<=2*k+1; i++) pat+="0";
            for(int i=1; i<=k; i++) st+="0";
            txt = st+s+st;
            int ts = txt.size();
            int ps = pat.size();
            for(int i=0; i<=ts-ps; i++){
                if(txt.compare(i, ps, pat)==0){
                    ans++;
                    txt[i+k]='1';
                }
            }
            cout<<ans<<endl;
        }
        fclose(stdin);
        // fclose(stdout);
    }
}