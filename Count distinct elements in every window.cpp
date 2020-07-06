#include<bits/stdc++.h>
using namespace std;

void winDist(int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        winDist(n, k);
        cout << endl;
    }
    return 0;
}

void winDist(int n, int k){
    int arr[n], count = 0;
    unordered_map<int, int> um;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < k; i++){
        um[arr[i]]++;
        if(um[arr[i]] == 1)
            count++;
    }
    cout << count << " ";
    for(int i = k; i < n; i++){
        um[arr[i - k]]--;
        if(um[arr[i - k]] == 0)
            count--, um.erase(um[arr[i - k]]);
        um[arr[i]]++;
        if(um[arr[i]] == 1)
            count++;
        cout << count << " ";
    }
}
