#include<bits/stdc++.h>
using namespace std;

string pairSumDiv(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << pairSumDiv(n) << endl;
	}
	return 0;
}

string pairSumDiv(int n){
    int arr[n], k, curr = 0;
    bool flag = false;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    for(int i = 0; i < n; i++){
        curr += arr[i];
        if(i % 2 != 0 && curr % k == 0){
            curr = 0;
            if(i == n - 1)
                flag = true;
        }
    }
    if(flag)
        return "True";
    else
        return "False";
}
