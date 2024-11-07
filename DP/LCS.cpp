#include <bits/stdc++.h>
using namespace std;

int const N = 1000;
int memo[N][N];

//-1 no calculated
int dp(string &s1, string &s2, int l, int r){
       if(l >= (int)s1.size()|| r >= (int)s2.size()) return 0;
       int &a = memo[l][r];
       if(a == -1){
          a = 0;
          if(s1[l] == s2[r]){
             a = dp(s1,s2,l+1, r+1)+1;
          }else{
             a = max(dp(s1,s2,l+1,r), dp(s1,s2,l,r+1));
          }
       }
       return a;
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s1,s2;cin>>s1>>s2;
    memset(memo, -1, sizeof(memo));
    cout<<dp(s1,s2,0,0);
    return 0;
}