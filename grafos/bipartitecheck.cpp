bool check(vector<vector<int>>& g, int n){
    vector<int> color(n + 1, -1);
    vector<bool> visi(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visi[i]) {
            queue<int> cola;
            cola.push(i);
            color[i] = 1;
            while (!cola.empty()) {
                int act = cola.front();
                cola.pop();
                if (visi[act]) continue;
                visi[act] = true;
                for (int &vecino : g[act]) {
                    if (color[vecino] == color[act]) {
                        return false;
                    } else if (!visi[vecino]) {
                        color[vecino] = 1 - color[act];
                        cola.push(vecino);
                    }
                }
            }
        }
    }
    return true;
}