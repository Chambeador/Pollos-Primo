void solve() {
    int n,m;cin>>n>>m;
    vector<int> g[n+1];
    for(int i = 0; i<m; i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n+1,1e9);
    vector<int> parent(n+1,-1);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(dist[v]>dist[u]+1){
                dist[v]=dist[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
    if(dist[n]==1e9){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<dist[n]+1<<"\n";
    vector<int> ans;
    int u=n;
    while(u!=-1){
        ans.push_back(u);
        u=parent[u];
    }
    reverse(all(ans));
    for(auto x:ans)cout<<x<<" ";
    cout<<"\n";    
}