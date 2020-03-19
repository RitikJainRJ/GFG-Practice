#include<bits/stdc++.h>
using namespace std;

string excel(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << excel(n) << endl;
	}
	return 0;
}

string excel(int n){
    unordered_map<int, char> um;
    string str;

    for(int i = 1; i <= 26; i++)
        um[i] = 'A' + i - 1;
    while(n){
        int temp = n % 26;
        if(temp == 0){
            str = um[26] + str;
            n = n / 26;
            n--;
        }
        else{
            str = um[temp] + str;
            n = n / 26;
        }
    }
    return str;
}
