void fillStack(int u, vector<int> *adj, vector<bool> &visited, stack<int> &s){
    visited[u] = true;

    for(auto it = adj[u].begin(); it != adj[u].end(); it++){
        int v = *it;
        if(!visited[v])
            fillStack(v, adj, visited, s);
    }
    s.push(u);
}

void transposeGraph(vector<int> *adj, vector<int> *trans, int n){
    for(int u = 0; u < n; u++){
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            int v = *it;
            trans[v].push_back(u);
        }
    }
}

void dfs(int u, vector<int> *adj, vector<bool> &visited){
    visited[u] = true;

    for(auto it = adj[u].begin(); it != adj[u].end(); it++){
        int v = *it;
        if(!visited[v])
            dfs(v, adj, visited);
    }
}

int kosaraju(int n, vector<int> *adj) {
    stack<int> s;
    vector<bool> visited;
    vector<int> *trans = new vector<int>[n];
    int res = 0;

    visited = vector<bool>(n, false);
    for(int i = 0; i < n; i++)
        if(!visited[i])
            fillStack(i, adj, visited, s);
    transposeGraph(adj, trans, n);
    visited = vector<bool>(n, false);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u]){
            res++;
            dfs(u, trans, visited);
        }
    }
    return res;
}
