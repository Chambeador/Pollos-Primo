#include<bits/stdc++.h>
#define int long long
using namespace std;

int const N = 105;
int memo[N][N];
int dp(vector<int> &arr, int l, int r){
    if(l+1 == r) return 0;//one matrix
    if(l+2 == r) return arr[l]*arr[l+1]*arr[l+2]; //two matrix
    int &a = memo[l][r];
    if(a == -1){
       a = 1e17;
       for(int i = l+1; i < r; i++){
          int precio = arr[l]*arr[i]*arr[r];
          a = min(a, dp(arr,l,i)+dp(arr,i,r)+precio);
       }
    }
    return a;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    memset(memo, -1, sizeof(memo));
    cout<<dp(arr,0, n-1);
    return 0;
}