#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll maxProSub(ll);

int main(){
	ll t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << maxProSub(n) << endl;
	}
	return 0;
}

ll maxProSub(ll n){
    ll arr[n];

    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    ll maxVal = 1, minVal = 1, res = INT_MIN;

    for(ll i = 0; i < n; i++){
        if(arr[i] > 0){
            maxVal = maxVal * arr[i];
            minVal = min(minVal * arr[i], 1);
        }
        else if(arr[i] < 0){
            ll prevMax = maxVal;
            maxVal = minVal * arr[i];
            minVal = prevMax * arr[i];
        }
        else {
            minVal = 1;
            maxVal = 0;
        }

        res = max(res, maxVal);
        if(maxVal <= 0)
            maxVal = 1;
    }
    return res;
}
