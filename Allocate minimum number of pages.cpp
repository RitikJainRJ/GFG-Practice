#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll minPages(ll);

int main(){
	ll t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << minPages(n) << endl;
	}
	return 0;
}

ll minPages(ll n){
    ll arr[n], l = 0, r = 0, ans = -1, m;

    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        l = max(l, arr[i]);
        r += arr[i];
    }
    cin >> m;
    if(n < m)
        return -1;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        ll sum = arr[0], temp = 1;

        for(ll i = 1; i < n; i++){
            sum += arr[i];
            if(sum > mid){
                temp++;
                sum = arr[i];
            }
        }
        if(temp <= m){
            ans = mid;
            r = mid - 1;
        }
        else if(temp > m){
            l = mid + 1;
        }
    }
    return ans;
}
