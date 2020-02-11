/*
3
3 3
1 2 3
-3 -2 -1
1 7 5
4 4
9 7 16 5
1 -6 -7 3
1 8 7 9
7 -2 0 10
*/
#include<bits/stdc++.h>
using namespace std;

void largestRec(int, int);
bool sumZero(int[], int, int&, int&);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        largestRec(n, m);
        cout << endl;
    }
    return 0;
}

void largestRec(int n, int m){
    int arr[n][m], load[n];
    int l, r, t, d;
    int left, right, top, down, max = INT_MIN;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(l = 0; l < m; l++){
        memset(load, 0, sizeof(load));
        for(r = l; r < m; r++){
            for(int i = 0; i < n; i++)
                load[i] += arr[i][r];
            if(sumZero(load, n, t, d)){
                int x = d - t + 1;
                int y = r - l + 1;
                int c = x * y;
                if(c > max){
                    max = c;
                    left = l;
                    right = r;
                    top = t;
                    down = d;
                }
            }
        }
    }
    if(max == INT_MIN){
        cout << "No matrix found" << endl;
        return;
    }
    for(int i = top; i <= down; i++){
        for(int j = left; j <= right; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool sumZero(int arr[], int n, int &t, int &d){
    int k = 0, curr_sum = 0, max = INT_MIN;
    unordered_multimap<int, int> um;

    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        um.insert({curr_sum, i});
        if(curr_sum == k){
            int temp = i + 1;
            if(max < temp){
                max = temp;
                t = 0;
                d = i;
            }
        }
        auto itr = um.equal_range(curr_sum - k);
        for(auto it = itr.first; it != itr.second; it++){
            int temp = i - it->second;
            if(max < temp){
                max = temp;
                d = i;
                t = it->second + 1;
            }
        }
    }
    if(max == INT_MIN)
        return false;
    return true;
}
