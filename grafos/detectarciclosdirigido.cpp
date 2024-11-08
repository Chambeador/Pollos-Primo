vector<vector<int>> adj(2e5+5);
vector<int> visited(2e5);
bool ok = false; // if cycle was found ok is true
vector<int> cycle;
void dfs(int x, vector<int> &st) {
    if (ok || visited[x] == 2) {
        return;
    } else if (visited[x] == 1) {
        cycle.pb(x);
        while (st.back() != x) {
            cycle.pb(st.back());
            st.pop_back();
        }
        cycle.pb(x);
        reverse(aint(cycle));
        ok = true;
        return;
    }
    visited[x] = 1;
    st.pb(x);
    for (auto y : adj[x]) {
        dfs(y, st);
    }
    st.pop_back();
    visited[x] = 2;
}

void test_case() {
    int n, m;
    cin >> n >> m;
    
    for (int i =0; i < m;i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }

    vector<int> st;
    for (int i = 1; i <= n; i++) {
        dfs(i, st);
    }

    if (ok) {
        //haycilo e imprimir
    }
}