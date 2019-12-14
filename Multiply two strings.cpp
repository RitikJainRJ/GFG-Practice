/*
Given two numbers as strings. The numbers may be very large (may not fit in long long int),
the task is to find product of these two numbers.
*/
#include<bits/stdc++.h>
using namespace std;

bool isGreater(string, string);
void multiply(string, string);
string addString(string, string);
string _add(string, string);

int main(void){
    int t;
    string s1, s2;

    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        multiply(s1, s2);
        cout << endl;
    }
    return 0;
}

void multiply(string s1, string s2){
    int l1, l2;
    string res1, res2;

    l1 = s1.length();
    l2 = s2.length();
    for(int j = l2 - 1, k = 0; j >= 0; j--, k++){
        int c = 0;
        res1.erase();
        for(int i = l1 - 1; i >= 0; i--){
            int temp = (s2[j] - '0') * (s1[i] - '0') + c;
            char ld = (temp % 10) + '0';
            res1 = ld + res1;
            c = temp / 10;
        }
        while(c){
            char ld = (c % 10) + '0';
            res1 = ld + res1;
            c /= 10;
        }
        int temp = k;
        while(temp--)
            res1.push_back('0');
        res2 = addString(res1, res2);
    }
    cout << res2;
}

bool isGreater(string a, string b){
    if(a.length() > b.length())
        return true;
    else if(a.length() < b.length())
        return false;
    else{
        for(int i = 0; i < a.length(); i++){
            if(a[i] > b[i])
                return true;
            else if(a[i] < b[i])
                return false;
        }
        return true;
    }
}

string addString(string a, string b){
    if(isGreater(a, b))
        return _add(a, b);
    else
        return _add(b, a);
}

string _add(string a, string b){
    string res;
    int c = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < b.length(); i++){
        int temp = (a[i] - '0') + (b[i] - '0') + c;
        res.push_back((temp % 10) + '0');
        c = temp / 10;
    }
    for(int i = b.length(); i < a.length(); i++){
        int temp = (a[i] - '0') + c;
        res.push_back((temp % 10) + '0');
        c = temp / 10;
    }
    while(c){
        char ld = (c % 10) + '0';
        res.push_back(ld);
        c /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
