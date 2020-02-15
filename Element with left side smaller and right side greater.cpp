#include<bits/stdc++.h>
using namespace std;

int findElement(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << findElement(n) << endl;
    }
    return 0;
}

int findElement(int n){
    int arr[n], curr;
    bool valid[n];

    memset(valid, true, sizeof(valid));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    curr = arr[n - 1];
    for(int i = n - 2; i > 0; i--){
        if(arr[i] <= curr){
            curr = arr[i];
        }
        else{
            valid[i] = false;
        }
    }
    curr = arr[0];
    for(int i = 1; i < n - 1; i++){
        if(curr > arr[i]){
            valid[i] = false;
        }
        else{
            curr = arr[i];
            if(valid[i] == true)
                return arr[i];
        }
    }
    return -1;
}
