/*
Given two numbers as strings. The numbers may be very large (may not fit in long long int),
the task is to find difference of these two numbers.
*/
#include<bits/stdc++.h>
using namespace std;

bool isGreater(string, string);
void findDiff(string, string);

int main(void){
    int t;
    string s1, s2;

    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        if(isGreater(s1, s2))
            findDiff(s1, s2);
        else
            findDiff(s2, s1);
        cout << endl;
    }
    return 0;
}

bool isGreater(string s1, string s2){
    if(s1.length() > s2.length())
        return true;
    else if(s1.length() < s2.length())
        return false;
    for(int i = 0; i < s1.length(); i++){
        if((s1[i] - '0') > (s2[i] - '0')){
            return true;
        }
        else if((s1[i] - '0') < (s2[i] - '0')){
            return false;
        }
    }
    return true;
}

void findDiff(string s1, string s2){
    string res;
    int c = 0;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(int i = 0; i < s2.length(); i++){
        int temp = (s1[i] - '0') - (s2[i] - '0') - c;
        if(temp < 0){
            temp += 10;
            c = 1;
        }
        else
            c = 0;
        res.push_back(temp + '0');
    }
    for(int i = s2.length(); i < s1.length(); i++){
        int temp = (s1[i] - '0') - c;
        if(temp < 0){
            temp += 10;
            c = 1;
        }
        else
            c = 0;
        res.push_back(temp + '0');
    }
    reverse(res.begin(), res.end());
    cout << res;
}
