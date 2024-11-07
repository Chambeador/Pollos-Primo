#include <bits/stdc++.h>
using namespace std;
 

vector<int> lis(vector<int> &v){
    int n = v.size();
    vector<int> dp; 
    dp.push_back(-1e9); 
    vector<int> curr(n); 
    for (int i = 0; i < n; i++) {
        int l = 0, r = dp.size()-1;
        int pos = dp.size();
        while (l <= r) {
            int m = l + (r-l) / 2;
            if(dp[m] >= v[i]){
                pos = m; 
                r = m - 1; 
            }else{
                l = m + 1;
            }
        }
        curr[i] = pos; 
        if (pos == dp.size()) {
            dp.push_back(v[i]);
        } else {
            dp[pos] = v[i];
        }
    }
    vector<int> ans;
    int x = dp.size() - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (curr[i] == x) {
            ans.push_back(v[i]);
            x--;
        }
    }
    reverse(ans.begin(), ans.end()); 
    return ans;
}


signed main() {
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n; cin>>n;vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    vector<int> ans = lis(arr);
    cout<<ans.size()<<endl;
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}