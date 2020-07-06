#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int maxAct(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << maxAct(n) << endl;
	}
	return 0;
}

int maxAct(int n){
    int s[n], e[n], res = 0, m;
    vector<pii> arr(n);

    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        cin >> e[i];
    for(int i = 0; i < n; i++)
        arr[i] = {s[i], e[i]};
    sort(arr.begin(), arr.end(), [&](pii &a, pii &b){
        return a.second < b.second;
    });
    m = arr[0].second, res = 1;
    for(int i = 1; i < n; i++){
        if(m <= arr[i].first){
            res++;
            m = arr[i].second;
        }
    }
    return res;
}
