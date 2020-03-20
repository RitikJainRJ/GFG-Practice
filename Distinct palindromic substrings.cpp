#include<bits/stdc++.h>
using namespace std;

int distinctPalindrome(string);

int main(){
	int t;
	string str;

	cin >> t;
	while(t--){
	    cin >> str;
	    cout << distinctPalindrome(str) << endl;
	}
	return 0;
}

int distinctPalindrome(string str){
    int l = str.length();
    bool dp[l][l];
    unordered_set<string> us;

    for(int i = 0; i < l; i++){
        dp[i][i] = true;
        string temp(1, str[i]);
        us.insert(temp);
    }
    for(int cl = 2; cl <= l; cl++){
        for(int i = 0; i < l - cl + 1; i++){
            int j = i + cl - 1;
            if(cl == 2){
                if(str[i] == str[j]){
                    dp[i][j] = true;
                    string temp = str.substr(i, j - i + 1);
                    us.insert(temp);
                }
                else
                    dp[i][j] = false;
            }
            else{
                if(str[i] == str[j] && dp[i + 1][j - 1]){
                    dp[i][j] = true;
                    string temp = str.substr(i, j - i + 1);
                    us.insert(temp);
                }
                else
                    dp[i][j] = false;
            }
        }
    }
    return us.size();
}
