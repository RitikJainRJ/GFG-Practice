#include<bits/stdc++.h>
using namespace std;

int smallestWindow(string);

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << smallestWindow(str) << endl;
    }
	return 0;
}

int smallestWindow(string str){
    unordered_set<char> us;
    unordered_map<char, int> um;
    queue<char> q;
    int min = INT_MAX;

    for(int i = 0; i < str.length(); i++)
        us.insert(str[i]);
    for(int i = 0; i < str.length(); i++){
        q.push(str[i]);
        um[str[i]]++;
        if(um.size() == us.size()){
            if(min > q.size())
                min = q.size();
            char temp = q.front();
            um[temp]--;
            if(um[temp] == 0)
                um.erase(temp);
            q.pop();
        }
        while(1){
            char temp = q.front();
            if(um.find(temp) != um.end() && um[temp] > 1){
                um[temp]--;
                q.pop();
            }
            else
                break;
        }
    }
    return min;
}
