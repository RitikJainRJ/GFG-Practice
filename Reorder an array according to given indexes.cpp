#include<bits/stdc++.h>
using namespace std;

void reorder(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        reorder(n);
        cout << endl;
    }
    return 0;
}

void reorder(int n){
    int arr[n], index[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> index[i];
    for(int i = 0; i < n; i++){
        while(i != index[i]){
            int x = index[i];
            swap(arr[i], arr[x]);
            swap(index[i], index[x]);
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << index[i] << " ";
}
