bool isSafe(int x, int y, int mat[MAX][MAX], int **vis, int n){
    if(0 <= x && x < n && 0 <= y && y < n && mat[x][y] == 1 && vis[x][y] == 0)
        return true;
    return false;
}

void _printPath(int x, int y, int mat[MAX][MAX], int **vis, int n, string &ans, vector<string> &res){
    if(x == n - 1 && y == n - 1){
        res.push_back(ans);
        return;
    }
    int xMove[] = {1, 0, 0, -1};
    int yMove[] = {0, -1, 1, 0};
    for(int i = 0; i < 4; i++){
        int _x = x + xMove[i];
        int _y = y + yMove[i];
        if(isSafe(_x, _y, mat, vis, n)){
            char ch;
            if(i == 0)
                ch = 'D';
            else if(i == 1)
                ch = 'L';
            else if(i == 2)
                ch = 'R';
            else
                ch = 'U';
            vis[_x][_y] = 1;
            ans.push_back(ch);
            _printPath(_x, _y, mat, vis, n, ans, res);
            ans.pop_back();
            vis[_x][_y] = 0;
        }
    }
}

vector<string> printPath(int mat[MAX][MAX], int n){
    vector<string> res;
    string ans;
    int **vis = new int*[n];

    if(mat[0][0] == 0)
        return res;
    for(int i = 0; i < n; i++)
        vis[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            vis[i][j] = 0;
    vis[0][0] = 1;
    _printPath(0, 0, mat, vis, n, ans, res);
    return res;
}
