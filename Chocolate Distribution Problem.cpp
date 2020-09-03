#include<bits/stdc++.h>
using namespace std;

int chocoDis(int *arr, int n, int m){
    int res = INT_MAX;

    sort(arr, arr + n);
    for(int i = 0; i + m - 1 < n; i++)
        res = min(res, arr[i + m - 1] - arr[i]);
    return res;
}

int main(){
	int t, n, m;

	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[n];

	    for(int i = 0; i < n; i++)
	        cin >> arr[i];
	    cin >> m;
	    cout << chocoDis(arr, n, m) << endl;
	}
	return 0;
}
