#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

class Graph{
private:
    int n;
    int e;
    vector<pii> edge;

    int find(int num, vector<int> &p){
        if(p[num] == -1)
            return num;
        return find(p[num], p);
    }

public:
    Graph(int n, int e){
        this->n = n;
        this->e = e;
    }

    void addEdge(int u, int v){
        edge.push_back({u, v});
    }

    bool isCycle(){
        vector<int> p(n, -1);

        for(int i = 0; i < e; i++){
            int a = find(edge[i].first, p);
            int b = find(edge[i].second, p);
            if(a == b)
                return true;
            //union
            p[b] = a;
        }
        return false;
    }

};

int main(){
    Graph g(3, 2);
    int u, v;

    for(int i = 0; i < 2; i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << g.isCycle() << endl;
    return 0;
}
