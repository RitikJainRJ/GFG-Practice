/*
Given an array with positive number the task to find the largest subsequence from array
that contain elements which are Fibonacci numbers.
*/

#include<bits/stdc++.h>
using namespace std;

void lfs(int);

bool arr[1001];

int main(){
	int t, n;

	memset(arr, false, sizeof(arr));
	int a = 0, b = 1, c;
	arr[a] = true;
	arr[b] = true;
	while(1){
	    c = a + b;
	    a = b;
	    b = c;
	    if(c >= 1000)
	        break;
	    arr[c] = true;
	}
	cin >> t;
	while(t--){
	    cin >> n;
	    lfs(n);
	    cout << endl;
	}
	return 0;
}

void lfs(int n){
    int temp[n];

    for(int i = 0; i < n; i++)
        cin >> temp[i];
    for(int i = 0; i < n; i++)
        if(arr[temp[i]] == true)
            cout << temp[i] << " ";
}
