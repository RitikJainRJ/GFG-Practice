#include<bits/stdc++.h>
using namespace std;

int GCD(int);
int _gcd(int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << GCD(n) << endl;
    }
    return 0;
}

int _gcd(int a, int b){
    if(b == 0)
        return a;
    return _gcd(b, a % b);
}

int GCD(int n){
    int arr[n];
    int res;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    res = arr[0];
    for(int i = 1; i < n; i++)
        res = _gcd(res, arr[i]);
    return res;
}
