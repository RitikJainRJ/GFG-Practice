#include<bits/stdc++.h>
using namespace std;

void addString(string, string);

int main(void){
    int t;
    string s1, s2;

    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        if(s1.length() >= s2.length())
            addString(s1, s2);
        else
            addString(s2, s1);
        cout << endl;
    }
    return 0;
}

void addString(string s1, string s2){
    int c = 0;
    string res;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(int i = 0; i < s2.length(); i++){
        int temp = (s1[i] - '0') + (s2[i] - '0') + c;
        char ld = (temp % 10) + '0';
        res.push_back(ld);
        c = temp / 10;
    }
    for(int i = s2.length(); i < s1.length(); i++){
        int temp = (s1[i] - '0') + c;
        char ld = (temp % 10) + '0';
        res.push_back(ld);
        c = temp / 10;
    }
    while(c){
        char temp = (c % 10) + '0';
        res.push_back(temp);
        c /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res;
}
