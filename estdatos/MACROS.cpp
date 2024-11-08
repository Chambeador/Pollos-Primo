#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int long long
#define uset unordered_set
#define f first
#define sst stringstream
#define s second
#define umap unordered_map
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define floatigual(a, b) (fabs(a - b) < EPS)
#define mod(a) md(a, MOD)
#define fore(i, a, n) for(int i = (a); i < (n); i++)
#define forb(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FORDD(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define techo(a, b) (a / b + (a % b != 0))
#define popcount(x) __builtin_popcountll(x);
using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vbol;
// typedef
// tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
// ordered_set; find_by_order kth largest  order_of_key < mt19937
// rng(chrono::steady_clock::now().time_since_epoch().count()); rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF = 1e100;
const double EPS = 1e-9;
const double PI = acos(-1);
// Modificar la constante para la criba
const int constante = 500;
vector<bool> criba(constante + 1);
vector<int> primos;
void eratostenes() {
    criba[0] = criba[1] = true;
    for (int i = 2; i <= constante; ++i) {
        if (!criba[i]) {
            primos.push_back(i);
            for (int j = i * i; j <= constante; j += i) {
                criba[j] = 1;
            }
        }
    }
}
int binpow(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else if (b < 0) {
        return 1 / binpow(a, -b);
    } else if (b % 2 == 0) {
        int we = binpow(a, b / 2);
        return we * we;
    } else {
        return a * binpow(a, b - 1);
    }
}
int gauss(int n) {
    int res = (((n % MOD) * ((n + 1) % MOD)) % MOD) / 2;
    return res;
}
int expMod(int base, int exponente, int mod) {
    int res = 1;
    base %= mod;
    while (exponente > 0) {
        if (exponente % 2 == 1) res = (res * base) % mod;
        exponente >>= 1;
        base = (base * base) % mod;
    }
    return res;
}
class UnionFind {
    vector<int> parents;
    vector<int> sizes;
 
   public:
    UnionFind(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }
    }
    int find(int x) {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
    bool join(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) {
            return false;
        }
        if (sizes[x_root] < sizes[y_root]) {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
};

void solve() {
    
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;while(t--)solve();
    solve();
}
//PLUS ULTRA RECARGADO!!!