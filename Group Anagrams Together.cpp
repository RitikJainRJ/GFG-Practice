#include<bits/stdc++.h>
using namespace std;

void groupAnagrams(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    groupAnagrams(n);
	    cout << endl;
	}
	return 0;
}

void groupAnagrams(int n){
    string arr[n];
    unordered_map<string, int> um;
    multiset<int> os;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        sort(arr[i].begin(), arr[i].end());
    for(int i = 0; i < n; i++)
        um[arr[i]]++;
    for(auto it = um.begin(); it != um.end(); it++)
        os.insert(it->second);
    for(auto it = os.begin(); it != os.end(); it++)
        cout << *it << " ";
}
