#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<pair<int, int>> monstruos;
vector<vector<int>> lava(1000 + 10, vector<int>(1000 + 10, INT_MAX));
pair<int, int> inicio, fin;
// 0 = U   1 = D   2 = R    3 = L
// Estos indices se usan para calc
vector<pair<int, int>> mov = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
char calc(int x) {
    char res;
    switch (x) {
        case 0:
            res = 'U';
            break;
        case 1:
            res = 'D';
            break;
        case 2:
            res = 'R';
            break;
        case 3:
            res = 'L';
            break;
    }
    return res;
}
vector<vector<char>> direcciones(1000 + 10, vector<char>(1000 + 10, '#'));
void reconstruircamino() {
    vector<char> res;
    auto [x, y] = fin;
    while (direcciones[x][y] != '$') {
        char aux = direcciones[x][y];
        res.push_back(aux);
        if (aux == 'U') {
            x++;
        } else if (aux == 'D') {
            x--;
        } else if (aux == 'L') {
            y++;
        } else {
            y--;
        }
    }
    cout << (int)res.size() << '\n';
    reverse(res.begin(), res.end());
    for (char& it : res) { cout << it; }
    cout << '\n';
}
bool esvalida(int x, int y, int tiempo) {
    if (x < 0 or y < 0 or x >= n or y >= m) { return false; }
    if (lava[x][y] <= tiempo) { return false; }
    return true;
}

bool esSalida(int x, int y, int tiempo) {
    if (!esvalida(x, y, tiempo)) return false;
    if (x == 0 or y == 0 or x == n - 1 or y == m - 1) return true;
    return false;
}

bool bfsDeSalida() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(inicio, 0));
    direcciones[inicio.first][inicio.second] = '$';
    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int tiempo = q.front().second;
        tiempo++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            auto mv = mov[i];
            int tx = cx + mv.first;
            int ty = cy + mv.second;
            if (esSalida(tx, ty, tiempo)) {
                direcciones[tx][ty] = calc(i);
                fin = { tx, ty };
                return true;
            }
            if (esvalida(tx, ty, tiempo)) {
                direcciones[tx][ty] = calc(i);
                lava[tx][ty] = tiempo;
                q.push({ { tx, ty }, tiempo });
            }
        }
    }
    return false;
}

void precalculoLava() {
    queue<pair<pair<int, int>, int>> q;
    for (auto m : monstruos) { q.push(make_pair(m, 0)); }
    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int tiempo = q.front().second;
        tiempo++;
        q.pop();

        for (auto mv : mov) {
            int tx = cx + mv.first;
            int ty = cy + mv.second;
            if (esvalida(tx, ty, tiempo)) {
                lava[tx][ty] = tiempo;
                q.push({ { tx, ty }, tiempo });
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '#') {
                lava[i][j] = 0;
            } else if (c == 'M') {
                lava[i][j] = 0;

                monstruos.push_back({ i, j });
            } else if (c == 'A') {
                lava[i][j] = 0;
                inicio = { i, j };
            } else {
                lava[i][j] = INT_MAX;
            }
        }
    }
    if (inicio.first == 0 or inicio.second == 0 or inicio.first == n - 1 or
        inicio.second == m - 1) {
        cout << "YES" << endl;
        cout << 0;
        return 0;
    }
    precalculoLava();

    if (!bfsDeSalida()) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    reconstruircamino();
}