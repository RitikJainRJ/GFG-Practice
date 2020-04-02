#include<bits/stdc++.h>
#define ll long long
using namespace std;

void nextLarger(ll);

int main(){
	ll t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    nextLarger(n);
	    cout << endl;
	}
	return 0;
}

void nextLarger(ll n){
    ll arr[n], res[n];
    stack<ll> s;

    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    ll i = 0;
    while(i < n){
        if(s.empty() || arr[i] < arr[s.top()])
            s.push(i++);
        else{
            ll temp = s.top();
            s.pop();
            res[temp] = arr[i];
        }
    }
    while(!s.empty()){
        ll temp = s.top();
        s.pop();
        res[temp] = -1;
    }
    for(ll i = 0; i < n; i++)
        cout << res[i] << " ";
}
