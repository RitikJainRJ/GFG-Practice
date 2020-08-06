#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

void bfs(int sx, int sy, vector<vector<int>> &dp, vector<vector<int>> &mat){
    int xMove[] = {-1, 0, 1, 0};
    int yMove[] = {0, 1, 0, -1};
    int n = mat.size(), m = mat[0].size();
    queue<pii> q;

    dp[sx][sy] = 0;
    q.push({sx, sy});
    while(!q.empty()){
        pii f = q.front();
        q.pop();
        int x = f.first, y = f.second;
        int d = dp[x][y];

        for(int i = 0; i < 4; i++){
            int nx = x + xMove[i];
            int ny = y + yMove[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && mat[nx][ny] == 1 && d + 1 < dp[nx][ny])
                dp[nx][ny] = d + 1, q.push({nx, ny});
        }
    }
}

int rottenOranges(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size(), res = 0;
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 2)
                bfs(i, j, dp, mat);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 1 && dp[i][j] == INT_MAX)
                return -1;
            else if(dp[i][j] != INT_MAX)
                res = max(res, dp[i][j]);
    return res;
}

int main(){
	int t, n, m;

	cin >> t;
	while(t--){
	    cin >> n >> m;
	    vector<vector<int>> mat(n, vector<int>(m));

	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < m; j++)
	            cin >> mat[i][j];
	    cout << rottenOranges(mat) << endl;
	}
	return 0;
}
