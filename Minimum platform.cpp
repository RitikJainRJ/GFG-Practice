#include<bits/stdc++.h>
using namespace std;

int minimumPlatform(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << minimumPlatform(n) << endl;
	}
	return 0;
}

int minimumPlatform(int n){
    int arr[n], dep[n];
    int dp[2400], res = 0;

    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> dep[i];
    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= dep[i]; j++){
            dp[j]++;
            if(dp[j] > res)
                res = dp[j];
        }
    }
    return res;
}
