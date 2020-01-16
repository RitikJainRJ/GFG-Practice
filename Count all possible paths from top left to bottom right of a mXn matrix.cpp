#include<bits/stdc++.h>
#define ll unsigned long long
#define MAX 1000000007
using namespace std;

ll findPath(ll, ll);
ll _findPath(ll, ll);

int main(){
    ll t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << _findPath(n, m) << endl;
    }
    return 0;
}

ll _findPath(ll n, ll m){
    ll arr[n][m];

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++){
            if(i == 0 || j == 0)
                arr[i][j] = 1;
            else
                arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % MAX;
        }
    return arr[n - 1][m - 1];
}

ll findPath(ll n, ll m){
    if(n == 1 && m == 1){
        return 1;
    }
    if(n < 1 || m < 1)
        return 0;
    return findPath(n - 1, m) + findPath(n, m - 1);
}
