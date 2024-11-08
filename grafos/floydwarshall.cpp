const int inf = 1e9;
vector<vector<pair<int, int>>> adj;
int distance[n][n];

void floydWarshaint() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			distance[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto p : adj[i]) {
			int b = p.first;
			int w = p.second;
			distance[i][b] = w;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}
}