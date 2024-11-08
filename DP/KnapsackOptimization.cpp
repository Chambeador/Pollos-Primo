#include <bits/stdc++.h>
using namespace std;
 
 //Knapsack Optimization memory O(2*W)
void solve(){
     int n,x; cin>>n>>x;
     vector<int> v(n);
     vector<int> w(n);
     for(int i = 0; i < n; i++)cin>>w[i];
     for(int i = 0; i < n; i++)cin>>v[i];
     vector<int> ant(x+1, 0);
     for(int i = 1; i <= n; i++){
        vector<int> act(x+1, 0);
         for(int j = 0; j <= x; j++){
             int w1 = w[i-1];
             int v1 = v[i-1];
             int t = (j >= w1? ant[j-w1]+v1:0); //dp[i-1][j-value]
             int nt = ant[j]; //dp[i-1][j]
             act[j]= max(t, nt);
         }
         ant = act;
     }
     cout<<ant[x]<<endl;
}
 
signed main() {
    solve();
    return 0;
}