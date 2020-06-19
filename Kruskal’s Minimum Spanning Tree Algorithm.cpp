#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int u, v, w;

    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class Graph{
private:
    int n;
    int e;
    vector<Edge> edges;

    int find(int num, vector<int> &parent){
        if(parent[num] == -1)
            return num;
        return find(parent[num], parent);
    }

public:
    Graph(int n, int e){
        this->n = n;
        this->e = e;
    }

    void addEdge(int u, int v, int w){
        edges.push_back(Edge(u, v, w));
    }

    int mst(){
        int res = 0, k = n - 1;
        vector<int> parent(n, -1);

        sort(edges.begin(), edges.end(), [&](Edge &a, Edge &b){
            return a.w < b.w;
        });
        for(int i = 0; i < e && k; i++){
            int a = find(edges[i].u, parent);
            int b = find(edges[i].v, parent);

            if(a == b)
                continue;
            parent[b] = a;
            res += edges[i].w;
            k--;
        }
        return res;
    }
};

int main(){
    int n, e, u, v, w;

    cin >> n >> e;
    Graph g(n, e);
    for(int i = 0; i < e; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cout << g.mst() << endl;
    return 0;
}
