#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int n;
    vector<vector<int>> mat;

    int _tsp(int u, int c, vector<bool> &visited){
        if(c == n - 1)
            return mat[u][0];
        int m = INT_MAX;
        visited[u] = true;

        for(int v = 0; v < n; v++){
            if(!visited[v]){
                m = min(m, mat[u][v] + _tsp(v, c + 1, visited));
            }
        }
        visited[u] = false;
        return m;
    }

public:
    Graph(int n, vector<vector<int>> &mat){
        this->n = n;
        this->mat = mat;
    }

    int tsp(){
        vector<bool> visited(n, false);

        return _tsp(0, 0, visited);
    }
};

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    vector<vector<int>> mat(n, vector<int>(n));

	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < n; j++)
	            cin >> mat[i][j];
	    Graph g(n, mat);
	    cout << g.tsp() << endl;
	}
	return 0;
}
