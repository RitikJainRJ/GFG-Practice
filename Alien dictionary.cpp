class Graph{
    private:
        int n;
        vector<int> *arr;
        int *indegree;

        bool _topoUtil(bool visited[], vector<int> &res);
    public:
        Graph(int n);
        void addEdge(int u, int v);
        string topoSort();
};

Graph::Graph(int n){
    this->n = n;
    arr = new vector<int>[n];
    indegree = new int[n];
    for(int i = 0; i < n; i++)
        indegree[i] = 0;
}

void Graph::addEdge(int u, int v){
    arr[u].push_back(v);
    indegree[v]++;
}

string Graph::topoSort(){
    bool visited[n];
    vector<int> res;
    string ans;

    memset(visited, false, sizeof(visited));
    _topoUtil(visited, res);
    for(int i = 0; i < n; i++){
        ans = ans + (char)(res[i] + 97);
    }
    return ans;
}

bool Graph::_topoUtil(bool visited[], vector<int> &res){
    if(res.size() == n)
        return true;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0 && visited[i] == false){
            visited[i] = true;
            for(int j = 0; j < arr[i].size(); j++)
                indegree[arr[i][j]]--;
            res.push_back(i);
            if(_topoUtil(visited, res))
                return true;
            visited[i] = false;
            for(int j = 0; j < arr[i].size(); j++)
                indegree[arr[i][j]]--;
            res.pop_back();
        }
    }
    return false;
}

string printOrder(string dict[], int n, int k) {
    Graph g(k);

    for(int i = 0; i < n - 1; i++){
        string word1 = dict[i], word2 = dict[i + 1];

        for(int j = 0; j < word1.length() && j < word2.length(); j++){
            if(word1[j] != word2[j]){
                g.addEdge(word1[j] - 97, word2[j] - 97);
                break;
            }
        }
    }
    return g.topoSort();
}



