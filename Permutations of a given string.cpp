#include<bits/stdc++.h>
using namespace std;

void permute(string, string);

int main(){
    int t;
    string str, res;

    cin >> t;
    while(t--){
        cin >> str;
        sort(&str[0], &str[0] + str.length());
        permute(res, str);
        cout << endl;
    }
	return 0;
}

void permute(string res, string str){
    if(str.empty()){
        cout << res << " ";
        return;
    }
    for(int i = 0; i < str.length(); i++){
        string temp = str;
        temp.erase(i, 1);
        permute(res + str[i], temp);
    }
}
