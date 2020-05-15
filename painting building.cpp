/*
1
4 2 1
0 0 0 2
100 20
30 59
71 81
9 200
*/
#include<bits/stdc++.h>
using namespace std;

int minAmo(int, int, int);
void _minAmo(int, int[], int[], int, int, int, int&, int**);

int main(){
    int t, n, m, k;

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cout << minAmo(n, m, k) << endl;
    }
    return 0;
}

int minAmo(int n, int m, int k){
    int arr[n], temp[n] = {-1};
    int **mat = new int*[n];
    int res = INT_MAX;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mat[i] = new int[m];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    _minAmo(0, arr, temp, m, k, n, res, mat);
    if(res == INT_MAX)
        return -1;
    return res;
}

void _minAmo(int ind, int arr[], int temp[], int m, int k, int n, int &res, int **mat){
    if(ind == n){
        int sum = 0, part = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] == 0){
                sum += mat[i][temp[i] - 1];
                if(i - 1 >= 0 && temp[i - 1] != temp[i])
                    part++;
            }
        if(part + 1 == k)
            res = min(res, sum);
        return;
    }
    if(arr[ind] != 0){
        temp[ind] = arr[ind];
        _minAmo(ind + 1, arr, temp, m, k, n, res, mat);
        temp[ind] = -1;
        return;
    }
    for(int i = 1; i <= m; i++){
        temp[ind] = i;
        _minAmo(ind + 1, arr, temp, m, k, n, res, mat);
        temp[ind] = -1;
    }
}
