#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD =  1e9 +7;
const int N = 200005;
int fact[N];
int invfact[N];
 
int binpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
 
int inversoFermat(int a, int m){
    return binpow(a, m-2, m);
}
 
void procesar(){
     fact[0] = fact[1] = 1;
     invfact[0] = invfact[1] = inversoFermat(1, MOD);
     for(int i = 2; i < N; i++){
         fact[i] = i*fact[i-1]%MOD;
         invfact[i] = inversoFermat(fact[i], MOD);
     }
}
 
int nCk(int n, int k){
    if(k == n) return 1;
    if(k > n) return 0;
    int res = fact[n] * invfact[n-k] % MOD * invfact[k] % MOD;
    return res;
}
 
signed main(){
    int n,k; cin>>n>>k;
    procesar();
    cout<<nCk(n,k);
}