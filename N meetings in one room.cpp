#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &arr){
    int m;

    sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });
    cout << arr[0][2] << " ";
    m = arr[0][1];
    for(int i = 1; i < arr.size(); i++){
        if(m <= arr[i][0]){
            cout << arr[i][2] << " ";
            m = arr[i][1];
        }
    }
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
        cin >> n;
	    int s[n], e[n];
	    vector<vector<int>> arr(n);

	    for(int i = 0; i < n; i++)
	        cin >> s[i];
	    for(int i = 0; i < n; i++)
	        cin >> e[i];
	    for(int i = 0; i < n; i++)
	        arr[i] = vector<int>({s[i], e[i], i + 1});
	    solve(arr);
	    cout << endl;
	}
	return 0;
}
