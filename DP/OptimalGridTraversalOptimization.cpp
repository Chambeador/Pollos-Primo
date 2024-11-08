#include<bits/stdc++.h>

using namespace std;
int const MAX_N = 100;
int const MAX_M = 100;
int G[MAX_N][MAX_M];
int n,m;
int memo[2][MAX_M];

int calc_dp_optimized(){
    for(int i = n-1; i>= 0; i--){
        for(int j = m-1; j >= 0; --j){
            if(i == n-1 && j == m-1) memo[i%2][j] = G[i][j];
            else{
              memo[i%2][j] = 0;
              if(i < n-1){
                 memo[i%2][j] = max(memo[i%2][j], G[i][j]+memo[1-i%2][j]);
              }
              if(j < m-1){
                 memo[i%2][j] = max(memo[i%2][j], G[i][j]+memo[i%2][j+1]);
              }
            }
        }
    }
    return memo[0][0];
}

signed main(){
       memset(memo, -1, sizeof(memo));
       cin>>n>>m;
       for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
               cin>>G[i][j];
           }
       }
       cout<<calc_dp_optimized()<<endl;
}