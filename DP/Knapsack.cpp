#include <bits/stdc++.h>
using namespace std;
 
//dp[i][j] = max(dp[i-1][j], dp[i-1][j-value])
void solve(){
     int n,x; cin>>n>>x;
     vector<int> v(n);
     vector<int> w(n);
     for(int i = 0; i < n; i++)cin>>w[i];
     for(int i = 0; i < n; i++)cin>>v[i];
     vector<vector<int>> dp(n+1, vector<int> (x+1, 0));
     for(int i = 1; i <= n; i++){
         for(int j = 0; j <= x; j++){
             int w1 = w[i-1];
             int v1 = v[i-1];
             int t = (j >= w1? dp[i-1][j-w1]+v1:0);
             int nt = dp[i-1][j];
             dp[i][j] = max(t, nt);
         }
     }
     cout<<dp[n][x]<<endl;
}
 
signed main() {
    solve();
    return 0;
}