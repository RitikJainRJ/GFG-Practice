#include<bits/stdc++.h>
using namespace std;

string rearrange(string&, int);

int main(){
    int t, d;
    string s;

    cin >> t;
    while(t--){
        cin >> s >> d;
        cout << rearrange(s, d) << endl;
    }
    return 0;
}

string rearrange(string &s, int d){
    unordered_map<char, int> um;
    vector<stack<char>> bucket(s.length() + 1);
    string res(s.length(), '$');

    for(int i = 0; i < s.length(); i++)
        um[s[i]]++;
    for(auto it = um.begin(); it != um.end(); it++)
        bucket[it->second].push(it->first);
    int k = 0;
    for(int i = s.length(); i >= 0; i--){
        while(!bucket[i].empty()){
            char ch = bucket[i].top();
            int f = i;
            bucket[i].pop();
            for(int j = k; j < s.length() && f; j += d, f--){
                res[j] = ch;
            }
            if(f != 0)
                return "Cannot be rearranged";
            while(res[k] != '$' && k < s.length())
                k++;
        }
    }
    return res;
}
