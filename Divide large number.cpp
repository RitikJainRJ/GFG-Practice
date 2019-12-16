#include<bits/stdc++.h>
using namespace std;

void divideLarge(string, string);

int main(void){
    int t;
    string s1, s2;

    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        divideLarge(s1, s2);
        cout << endl;
    }
    return 0;
}

void divideLarge(string s1, string s2){
    int i = 0, b = stoi(s2), temp = 0;
    string res;

    while(b > temp){
        temp = temp * 10 + (s1[i] - '0');
        i++;
    }
    while(i <= s1.length()){
        res += ((temp / b) + '0');
        temp = (temp % b) * 10 + (s1[i] - '0');
        i++;
    }
    cout << res;
}
