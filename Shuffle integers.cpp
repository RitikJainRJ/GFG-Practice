#include<bits/stdc++.h>
using namespace std;

void shuffle(int);
void _shuffle(int[], int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        shuffle(n);
        cout << endl;
    }
    return 0;
}

void shuffle(int n){
    int arr[n], m;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    _shuffle(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void _shuffle(int arr[], int s, int e){
    int m, mf, ss;

    if(s > e)
        return;
    if(s + 1 == e)
        return;
    m = (s + e) / 2;
    mf = (s + m) / 2;
    ss = m + 1;
    for(int i = mf + 1; i <= m; i++)
        swap(arr[i], arr[ss++]);
    for(int i = s; i <= e; i++)
        cout << arr[i] << " ";
    cout << endl;
    _shuffle(arr, s, m);
    _shuffle(arr, m + 1, e);
}
