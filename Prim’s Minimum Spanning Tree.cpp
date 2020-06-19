#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int n;
    vector<vector<int>> mat;

    int minKey(vector<int> &key, vector<bool> &mstSet){
        int m = INT_MAX, res;

        for(int i = 0; i < n; i++)
            if(!mstSet[i] && m > key[i])
                m = key[i], res = i;
        return res;
    }

public:
    Graph(int n, vector<vector<int>>& mat){
        this->n = n;
        this->mat = mat;
    }

    void prims(int s){
        vector<bool> mstSet(n, false);
        vector<int> key(n, INT_MAX), p(n);

        key[s] = 0;
        p[s] = -1;
        for(int i = 0; i < n - 1; i++){
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for(int v = 0; v < n; v++)
                if(mat[u][v] && !mstSet[v] && mat[u][v] < key[v])
                    key[v] = mat[u][v], p[v] = u;
        }
        for(int i = 1; i < n; i++)
            cout << p[i] << ", " << i << " -->" << mat[i][p[i]] << endl;
    }
};

int main(){
    vector<vector<int>> mat({{ 0, 2, 0, 6, 0 },
                             { 2, 0, 3, 8, 5 },
                             { 0, 3, 0, 0, 7 },
                             { 6, 8, 0, 0, 9 },
                             { 0, 5, 7, 9, 0 }});
    Graph g(5, mat);
    g.prims(0);
    return 0;
}
