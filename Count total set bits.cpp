#include<bits/stdc++.h>
using namespace std;

int countSB(int n){
    int count = 0;
    int dp[n + 1];

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i ^ (i & -i)] + 1;
        count += dp[i];
    }
    return count;
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << countSB(n) << endl;
	}
	return 0;
}
