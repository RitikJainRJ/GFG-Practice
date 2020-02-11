#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll minCost(ll);

int main(){
	ll t, n;

	cin >> t;
	while(t--){
        cin >> n;
        cout << minCost(n) << endl;
	}
	return 0;
}

ll minCost(ll n){
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;

    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        pq.push(temp);
    }
    while(pq.size() > 1){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ll c = a + b;
        pq.push(c);
        sum += c;
    }
    return sum;
}
