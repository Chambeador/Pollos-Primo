vector<int> dijkstra(vector<vector<pair<int, int>>> &grafo, int n, int origen) {
    vector<int> distancia(n + 1, INF); 
    distancia[origen] = 0; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, origen});
 
 //   vector<int> padre(n + 1); 
    while (!pq.empty()) {
        auto [peso, nodo] = pq.top();
        pq.pop();
        if (distancia[nodo] < peso) {
            continue;
        }
 
        for (auto vecino : grafo[nodo]) {
            int destino = vecino.first;
            int costo = vecino.second; 
 
            if (distancia[nodo] + costo < distancia[destino]) {
                distancia[destino] = distancia[nodo] + costo;  
                pq.push({distancia[destino], destino});
            //    padre[destino] = nodo; 
            }
        }
    }
 
    return distancia;  
}
