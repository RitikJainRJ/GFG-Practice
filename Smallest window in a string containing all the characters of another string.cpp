#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string, string);

int main(){
    int T;
    string s, t;

    cin >> T;
    while(T--){
        cin >> s >> t;
        cout << smallestWindow(s, t) << endl;
    }
	return 0;
}

string smallestWindow(string s, string t){
    unordered_set<char> us;
    unordered_map<char, int> um;
    queue<char> q, res;
    int min = INT_MAX;
    string ans;
    bool flag = false;

    for(int i = 0; i < t.length(); i++)
        us.insert(t[i]);
    for(int i = 0; i < s.length(); i++){
        if(us.find(s[i]) != us.end()){
            q.push(s[i]);
            um[s[i]]++;
            while(1){
                char temp = q.front();
                if(um.find(temp) != um.end() && um[temp] > 1){
                    um[temp]--;
                    q.pop();
                }
                else if(um.find(temp) == um.end())
                    q.pop();
                else
                    break;
            }
        }
        else{
            q.push(s[i]);
        }
        if(um.size() == us.size()){
            if(min > q.size()){
                min = q.size();
                res = q;
            }
            flag = true;
        }
    }
    if(!flag)
        return "-1";
    while(!res.empty()){
        ans.push_back(res.front());
        res.pop();
    }
    return ans;
}
