#include<bits/stdc++.h>
using namespace std;

int longPreSuf(string);

int main(){
	int t;
	string str;

	cin >> t;
	while(t--){
	    cin >> str;
	    cout << longPreSuf(str) << endl;
	}
	return 0;
}

int longPreSuf(string str){
    int n = str.length();
    int lps[n], len = 0, res = 0, i = 1;

    lps[0] = 0;
    while(i < n){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            res = max(res, len);
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return res;
}
