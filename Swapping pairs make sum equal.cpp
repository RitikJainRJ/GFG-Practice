#include<bits/stdc++.h>
using namespace std;

int isSwapEqual(int, int);

int main(){
	int t, n, m;

	cin >> t;
	while(t--){
	    cin >> n >> m;
	    cout << isSwapEqual(n, m) << endl;
	}
	return 0;
}

int isSwapEqual(int n, int m){
    int arr[n], sum1 = 0, sum2 = 0, target;
    unordered_set<int> us;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum1 += arr[i];
    }
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        us.insert(temp);
        sum2 += temp;
    }
    target = (sum1 - sum2) / 2;
    for(int i = 0; i < n; i++){
        int temp = (arr[i] - target);
        if(us.find(temp) != us.end())
            return 1;
    }
    return -1;
}
