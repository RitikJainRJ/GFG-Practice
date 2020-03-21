#include<bits/stdc++.h>
using namespace std;

int minTime(int, int);
int numPainters(int[], int, int);

int main(){
	int t, k, n;

	cin >> t;
	while(t--){
	    cin >> k >> n;
	    cout << minTime(n, k) << endl;
	}
	return 0;
}

int minTime(int n, int k){
    int arr[n], l = 0, r = 0, res;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        r += arr[i];
        l = max(l, arr[i]);
    }
    while(l <= r){
        int mid = l + (r - l) / 2;
        int paintersRequired = numPainters(arr, n, mid);

        if(paintersRequired <= k){
            r = mid - 1;
            res = mid;
        }
        else
            l = mid + 1;
    }
    return res;
}

int numPainters(int arr[], int n, int t){
    int total = 0, res = 1;

    for(int i = 0; i < n; i++){
        total += arr[i];
        if(total > t){
            total = arr[i];
            res++;
        }
    }
    return res;
}
