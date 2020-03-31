#include<bits/stdc++.h>
#define MAX 1000000007
#define ll unsigned long long
using namespace std;

ll friendsPairing(ll);

int main(){
	ll t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << friendsPairing(n) << endl;
	}
	return 0;
}

ll friendsPairing(ll n){
    ll arr[n + 1];

    arr[0] = 1;
    arr[1] = 1;
    for(ll i = 2; i <= n; i++)
        arr[i] = (arr[i - 1] + ((i - 1) * arr[i - 2]) % MAX) % MAX;
    return arr[n];
}
