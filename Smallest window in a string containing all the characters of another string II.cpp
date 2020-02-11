#include<bits/stdc++.h>
using namespace std;

string minWindow(string, string);

int main(){
    int T;
    string s, t;

    cin >> T;
    while(T--){
        cin >> s >> t;
        cout << minWindow(s, t) << endl;
    }
    return 0;
}

string minWindow(string s, string t){
    int hash_pat[256] = {0};
    int hash_str[256] = {0};

    for(int i = 0; i < t.length(); i++)
        hash_pat[t[i]]++;

    int i = 0, count = 0, min = INT_MAX;
    bool flag = false;
    string res;
    for(int j = 0; j < s.length(); j++){
        hash_str[s[j]]++;

        if(hash_pat[s[j]] != 0 && hash_str[s[j]] <= hash_pat[s[j]])
            count++;
        if(count == t.length()){
            while(hash_pat[s[i]] == 0 || hash_str[s[i]] > hash_pat[s[i]]){
                if(hash_str[s[i]] > hash_pat[s[i]]){
                    hash_str[s[i]]--;
                }
                i++;
            }
            int temp = j - i + 1;
            if(min > temp){
                min = temp;
                flag = true;
                res = s.substr(i, temp);
            }
        }
    }
    if(!flag)
        return "-1";
    return res;
}
