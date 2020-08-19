#include<bits/stdc++.h>
using namespace std;

int minCostPath(vector<vector<int>> &mat){
    int xMove[] = {-1, 0, 1, 0};
    int yMove[] = {0, 1, 0, -1};
    int n = mat.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    set<vector<int>> visited;

    dist[0][0] = mat[0][0];
    visited.insert({dist[0][0], 0, 0});
    while(!visited.empty()){
        vector<int> vec = *visited.begin();
        visited.erase(visited.begin());
        int x = vec[1], y = vec[2], d = vec[0];

        for(int i = 0; i < 4; i++){
            int nx = x + xMove[i];
            int ny = y + yMove[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n && dist[x][y] + mat[nx][ny] < dist[nx][ny]){
                if(visited.find({dist[nx][ny], nx, ny}) != visited.end())
                    visited.erase({dist[nx][ny], nx, ny});
                dist[nx][ny] = dist[x][y] + mat[nx][ny];
                visited.insert({dist[nx][ny], nx, ny});
            }
        }
    }
    return dist[n - 1][n - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    vector<vector<int>> mat(n, vector<int>(n));

	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < n; j++)
	            cin >> mat[i][j];
	    cout << minCostPath(mat) << endl;
	}
	return 0;
}
