#include<bits/stdc++.h>
using namespace std;

string largeNum(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << largeNum(n) << endl;
	}
	return 0;
}

bool myComp(string A, string B){
    int a = stoi(A + B), b = stoi(B + A);

    if(a > b)
        return 0;
    return 1;
}

string largeNum(int n){
    string arr[n];
    string res;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, myComp);
    for(int i = n - 1; i >= 0; i--)
        res = res + arr[i];
    return res;
}
