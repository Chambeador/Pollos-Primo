int n, m;
vector<string> mat(1000 + 10);
vector<vector<bool>> visi(1000 + 10, vector<bool>(1000 + 10));
//se  guarda en camino[i][j] desde donde llego
vector<vector<char>> camino(1000 + 10, vector<char>(1000 + 10));
vector<pair<int, int>i> direcciones = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
vector<char> direchar = { 'U', 'D', 'L', 'R' };
bool esval(int nx, int ny) {
    return nx >= 0 && ny >= 0 && nx < n && ny < m && !visi[nx][ny] &&
           mat[nx][ny] != '#';
}
bool bfs(pair<int, int>i ini, pair<int, int>i &fin) {
    queue<pair<int, int>i> q;
    q.push(ini);
    visi[ini.first][ini.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + direcciones[i].first;
            int ny = y + direcciones[i].second;

            if (esval(nx, ny)) {
                q.push({ nx, ny });
                visi[nx][ny] = true;
                camino[nx][ny] = direchar[i];
                if (mat[nx][ny] == 'B') {
                    fin = { nx, ny };
                    return true;
                }
            }
        }
    }

    return false;
}

void solve() {
    cin >> n >> m;
    pair<int, int>i ini, fin;
    FOR(i, n) {
        cin >> mat[i];
        FOR(j, m) {
            if (mat[i][j] == 'A') { ini = { i, j }; }
        }
    }

    if (bfs(ini, fin)) {
        cout << "YES\n";
        string cam;
        pair<int, int>i actual = fin;
        while (mat[actual.first][actual.second] != 'A') {
            char dirr = camino[actual.first][actual.second];
            cam += dirr;
            if (dirr == 'U')
                actual.first++;
            else if (dirr == 'D')
                actual.first--;
            else if (dirr == 'L')
                actual.second++;
            else if (dirr == 'R')
                actual.second--;
        }

        reverse(all(cam));
        cout << (int)cam.size() << '\n' << cam << '\n';
    } else {
        cout << "NO\n";
    }
}
