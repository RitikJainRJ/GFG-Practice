#include<bits/stdc++.h>
using namespace std;

int countOnion(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << countOnion(str) << endl;
    }
    return 0;
}

int countOnion(string str){
    stack<int> s;
    bool flag;
    int count = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            s.push(str[i]);
            flag = false;
        }
        else{
            if(s.empty())
                continue;
            if(flag == false){
                count++;
                flag = true;
            }
            s.pop();
        }
    }
    return count;
}
