int kruskal(vector<tuple<int,int,int>> &edges, int nodes) {
    union_find uf(nodes+1);
    //peso, u v
    sort(all(edges));
   // reverse(aint(edges)); // for maxst
    int answer = 0;
    for (auto edge : edges)  {
        int cost, a, b;
        tie(cost, a, b) = edge;
        if (uf.conectar(a, b)) 
            answer += cost;
    }
    return answer;
}