#include<bits/stdc++.h>
using namespace std;

int minDiff(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << minDiff(n) << endl;
	}
	return 0;
}

int minDiff(int n){
    int arr[n], sum = 0, res = INT_MAX, total;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    total = sum;
    sum = sum / 2;
    bool dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;
    for(int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - arr[i - 1] >= 0)
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    for(int i = sum; i >= 0; i--){
        if(dp[n][i] == true){
            res = total - i * 2;
            break;
        }
    }
    return res;
}
