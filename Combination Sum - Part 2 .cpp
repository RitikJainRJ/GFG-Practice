#include<bits/stdc++.h>
using namespace std;

bool combinations(int, int, vector<int>&, vector<int>&);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> arr(n), res;

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        sort(arr.begin(), arr.end());
        if(!combinations(0, k, arr, res))
            cout << "Empty";
        cout << endl;
    }
    return 0;
}

bool combinations(int i, int k, vector<int> &arr, vector<int> &res){
    if(k == 0){
        cout << "(" << res[0];
        for(int i = 1; i < res.size(); i++)
            cout << " " << res[i];
        cout << ")";
        return true;
    }
    else if(i == arr.size() || k < 0)
        return false;
    else{
        bool flag = false;
        res.push_back(arr[i]);
        flag = combinations(i + 1, k - arr[i], arr, res) || flag;
        res.pop_back();
        while(i + 1 < arr.size() && arr[i] == arr[i + 1])
            i++;
        flag = combinations(i + 1, k, arr, res) || flag;
        return flag;
    }
}
