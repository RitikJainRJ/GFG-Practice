#include<bits/stdc++.h>
using namespace std;

int swap(int n){
    int even = stoi("0101010101010101010101010101010", nullptr, 2);
    int odd = stoi("1010101010101010101010101010101", nullptr, 2);

    even = (n & even) >> 1;
    odd = (n & odd) << 1;
    return (even | odd);
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << swap(n) << endl;
	}
	return 0;
}
