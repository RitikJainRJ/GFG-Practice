#include<bits/stdc++.h>
using namespace std;

int sumLen(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << sumLen(n) << endl;
    }
    return 0;
}

int sumLen(int n){
    int arr[n], res = 0, prev = 0;
    unordered_map<int, int> um;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0, j;
    for(j = 0; j < n; j++){
        um[arr[j]]++;
        if(um[arr[j]] == 1){
            prev += j - i + 1;
            res += prev;
        }
        else{
            int n;
            while(arr[i] != arr[j]){
                um[arr[i]]--;
                i++;
            }
            um[arr[i]]--;
            i++;
            n = j - i + 1;
            prev = n * (n + 1) / 2;
            res += prev;
        }
    }
    return res;
}
