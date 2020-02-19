#include<bits/stdc++.h>
using namespace std;

int searchMatrix(int, int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << searchMatrix(n, m) << endl;
    }
    return 0;
}

int searchMatrix(int n, int m){
    int arr[n][m], x;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    cin >> x;
    int i = 0, j = m - 1;
    while(1){
        while(arr[i][j] > x && j >= 0)
            j--;
        if(j == -1)
            return 0;
        if(arr[i][j] == x)
            return 1;
        i++;
        if(i == n)
            return 0;
    }
    return 0;
}
