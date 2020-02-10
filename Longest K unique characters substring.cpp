#include<bits/stdc++.h>
using namespace std;

int longestSubstr(string, int);

int main(){
    int t, k;
    string s;

    cin >> t;
    while(t--){
        cin >> s >> k;
        cout << longestSubstr(s, k) << endl;
    }
    return 0;
}

int longestSubstr(string s, int k){
    queue<char> q;
    unordered_map<char, int> um;
    int max = 0;
    bool res = false;

    for(int i = 0; i < s.length(); i++){
        if(um.size() < k){
            q.push(s[i]);
            um[s[i]]++;
            if(um.size() == k)
                res = true;
        }
        else if(um.size() == k){
            res = true;
            if(um.find(s[i]) != um.end()){
                q.push(s[i]);
                um[s[i]]++;
            }
            else{
                while(1){
                    char temp = q.front();
                    q.pop();
                    um[temp]--;
                    if(um[temp] == 0){
                        um.erase(temp);
                        break;
                    }
                }
                q.push(s[i]);
                um[s[i]]++;
            }
        }
        if(max < q.size())
            max = q.size();
    }
    if(!res)
        return -1;
    return max;
}
