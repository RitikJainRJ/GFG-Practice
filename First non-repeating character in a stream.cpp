#include<bits/stdc++.h>
using namespace std;

void nonRepeat(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    nonRepeat(n);
	    cout << endl;
	}
	return 0;
}

void nonRepeat(int n){
    char arr[n];
    list<char> dq;
    unordered_map<char, list<char>::iterator> um;
    unordered_set<char> us;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(us.find(arr[i]) == us.end()){
            us.insert(arr[i]);
            dq.push_front(arr[i]);
            um[arr[i]] = dq.begin();
        }
        else{
            if(um.find(arr[i]) != um.end()){
                dq.erase(um[arr[i]]);
                um.erase(arr[i]);
            }
        }
        if(dq.empty())
            cout << -1 << " ";
        else
            cout << dq.back() << " ";
    }
}
