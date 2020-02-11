#include<bits/stdc++.h>
using namespace std;

int minDisWindow(string);

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        cout << minDisWindow(s) << endl;
    }
    return 0;
}

int minDisWindow(string s){
    int hash_pat[256] = {0}, hash_str[256] = {0};
    int length = 0;

    for(int i = 0; i < s.length(); i++){
        if(hash_pat[s[i]] == 0){
            length++;
            hash_pat[s[i]]++;
        }
    }
    int i = 0, count = 0, min = INT_MAX;
    for(int j = 0; j < s.length(); j++){
        hash_str[s[j]]++;
        if(hash_str[s[j]] == 1)
            count++;
        if(count == length){
            while(hash_str[s[i]] > 1){
                hash_str[s[i]]--;
                i++;
            }
            int temp = j - i + 1;
            if(min > temp)
                min = temp;
        }
    }
    return min;
}
