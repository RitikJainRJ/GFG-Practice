
#include<bits/stdc++.h>
using namespace std;

int numEven(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << numEven(n) << endl;
	}
	return 0;
}

int numEven(int n){
    int arr[n], curr = 0, result = 0;
    unordered_map<int, vector<int>> um;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        curr += arr[i];
        curr = curr % 2;
        if(curr == 0)
            result++;
        if(um.find(curr) != um.end())
            result = result + um[curr].size();
        um[curr].push_back(i);
    }
    return result;
}
