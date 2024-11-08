// Using djisktra, finds the k shortesth paths from 1 to n
// 2≤n≤10^5, 1≤m≤2⋅10^5, 1≤weight≤10^9, 1≤k≤10
// complexity seems O(k*m)
#define P pair<int,int>
void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> visited(n+1, 0);
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    vector<int> ans;
    priority_queue<P,vector<P>, greater<P>> q;
    q.push({0, 1});
    int kk = k;
    while (q.size()) {
        int x = q.top().S;
        int z = q.top().F;
        q.pop();
        if (visited[x] >= kk) {
            continue;
        }
        visited[x]++;
        if (x == n) {
            ans.pb(z);
            k--;
            if (k == 0) break;
        }
        for (auto yy : adj[x]) {
            q.push({yy.S + z, yy.F});
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i]<<' ';
    }
}