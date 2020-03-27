#include<bits/stdc++.h>
using namespace std;

int maxLength(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << maxLength(n) << endl;
	}
	return 0;
}

int maxLength(int n){
    string arr[n];
    int l, load[4] = {0}, res;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    l = arr[0].length();
    for(int i = 0; i < n; i++){
        if(arr[i][0] == 'R' && arr[i][l - 1] == 'R')
            load[0]++;
        else if(arr[i][0] == 'B' && arr[i][l - 1] == 'B')
            load[1]++;
        else if(arr[i][0] == 'R' && arr[i][l - 1] == 'B')
            load[2]++;
        else if(arr[i][0] == 'B' && arr[i][l - 1] == 'R')
            load[3]++;
    }
    if(load[2] == 0 && load[3] == 0){
        res = max(load[0], load[1]);
    }
    else if(load[2] == 0 || load[3] == 0){
        res = load[0] + load[1] + 1;
    }
    else if(load[2] == load[3]){
        int m = load[2];
        res = m + m + load[0] + load[1];
    }
    else{
        int m = min(load[2], load[3]);
        res = (m + (m + 1) + load[0] + load[1]);
    }
    if(res * l == l)
        return 0;
    return res * l;
}
