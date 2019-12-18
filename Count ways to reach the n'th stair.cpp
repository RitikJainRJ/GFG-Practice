/*
There are N stairs, a person standing at the bottom wants to reach the top.
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways,
the person can reach the top (order does matter).
*/
#include<bits/stdc++.h>
using namespace std;

int countWays(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << countWays(n) << endl;
    }
    return 0;
}

int countWays(int n){
    int arr[n + 1];

    arr[0] = arr[1] = 1;
    for(int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
    return arr[n];
}

/*recursive
int countWays(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return countWays(n - 1) + countWays(n - 2);
    }
}*/
