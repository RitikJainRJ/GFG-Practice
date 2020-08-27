#include<bits/stdc++.h>
using namespace std;

int minJumps(int *arr, int n){
    int fib[30], res = 0;
    int dp[n + 2];

    fib[0] = 0, fib[1] = 1;
    for(int i = 2; i < 30; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    dp[0] = 0;
    for(int i = 1; i <= n + 1; i++){
        dp[i] = INT_MAX;
        for(int j = 0; j < 30; j++)
            if(arr[i - 1] == 1 || i == n + 1 && i - fib[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - fib[j]]);
    }
    return dp[n + 1] == INT_MAX ? -1 : dp[n + 1];
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << minJumps(arr, n) << endl;
    }
    return 0;
}
