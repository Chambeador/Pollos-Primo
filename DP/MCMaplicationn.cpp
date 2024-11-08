#include <bits/stdc++.h>
using namespace std;
  
int memo1[501][501];
int memo2[501][501];
 
int dp(int l, int r, vector<int> &arr){
    if(l+1 == r && arr[r] != arr[l]) return 0;
    if(l+1 == r && arr[r] == arr[l]) return arr[l]+1;
    if(l == r) return arr[l];
    int &a = memo1[l][r];
    if(a == -1){
       a = 0;
       for(int i = l; i < r; i++){
           memo1[l][i] = dp(l, i,arr); 
           memo1[i+1][r] = dp(i+1, r,arr);
           if(memo1[l][i] == memo1[i+1][r] && memo1[l][i] != 0){
              memo1[l][r] = memo1[l][i]+1;
           }
       }
    }
    return a; 
}
 
int dp2(int l, int r, vector<int> &arr){
    if (l == r) return 1;
    if (memo2[l][r] != -1) return memo2[l][r];
    if (memo1[l][r] != 0) return memo2[l][r] = 1;
    int mini = r - l + 1;  
    for (int i = l; i < r; ++i) {
        mini = min(mini, dp2(l, i,arr) + dp2(i + 1, r,arr));
    }
    return memo2[l][r] = mini;
}
 
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo2));
    int n; cin>>n;
    vector<int>arr(n+1);
    for(int i = 1; i<= n; i++)cin>>arr[i];
    dp(1, n, arr);
    cout<<dp2(1, n, arr);
	return 0;
}