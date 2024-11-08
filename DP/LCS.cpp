#include <bits/stdc++.h>
using namespace std;

int const N = 1000;
int memo[N][N];
pair<int, int> path[N+1][N+1];
//-1 no calculated
int dp(string &s1, string &s2, int l, int r){
       if(l >= (int)s1.size()|| r >= (int)s2.size()){
          path[l][r] = {-1, -1}; return 0;
       }
       int &a = memo[l][r];
       if(a == -1){
          a = 0;
          if(s1[l] == s2[r]){
             path[l][r] = {l+1, r+1};
             a = dp(s1,s2,l+1, r+1)+1;
          }else{
             int op1 = dp(s1,s2,l+1,r);
             int op2 = dp(s1,s2,l,r+1);
             if(op1 > op2) path[l][r] = {l+1,r};
             else path[l][r] = {l, r+1};
             a = max(op1, op2);
          }
       }
       return a;
}

// Construct answer after DP
string construct(string &s1, string &s2) {
    int i, j;
    i = j = 0;
    string ans;
    while (i != -1 && j != -1) {
        if (s1[i] == s2[j]) {
            ans.push_back(s1[i]);
        }
        pair<int, int> aux = path[i][j];
        i = aux.first;
        j = aux.second;
    }
    return ans;
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s1,s2;cin>>s1>>s2;
    memset(memo, -1, sizeof(memo));
    cout<<dp(s1,s2,0,0)<<endl;
    cout<<construct(s1, s2)<<endl;
    return 0;
}