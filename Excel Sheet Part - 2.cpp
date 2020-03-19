#include<bits/stdc++.h>
using namespace std;

int excel(string);

int main(){
	int t;
	string str;

	cin >> t;
	while(t--){
	    cin >> str;
	    cout << excel(str) << endl;
	}
	return 0;
}

int excel(string str){
    int res = 0, temp = 1;

    for(int i = str.length() - 1, j = 0; i >= 0; i--, j++){
        res = res + temp * (str[i] - 'A' + 1);
        temp = temp * 26;
    }
    return res;
}
