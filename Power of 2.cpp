#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll t, n;

	cin >> t;
	while(t--){
	    cin >> n;

	    if(n > 0 && (ll)576460752303423488 % n == 0)
	        cout << "YES" << endl;
	    else
	        cout << "NO" << endl;
	}
	return 0;
}
