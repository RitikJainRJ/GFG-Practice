#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

void tinyURL(ll);
string id_to_string(ll);
ll string_to_id(string);

int main(){
    ll t, n;

    cin >> t;
    while(t--){
        cin >> n;
        tinyURL(n);
    }
    return 0;
}

void tinyURL(ll n){
    string res1 = id_to_string(n);
    cout << res1 << endl;
    ll res2 = string_to_id(res1);
    cout << res2 << endl;
}

string id_to_string(ll n){
    string str;
    string arr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    while(n){
        str.push_back(arr[n % 62]);
        n /= 62;
    }
    reverse(str.begin(), str.end());
    return str;
}

ll string_to_id(string str){
    ll res = 0;

    for(ll i = 0; i < str.length(); i++){
        if('a' <= str[i] && str[i] <= 'z')
            res = res * 62 + str[i] - 'a';
        else if('A' <= str[i] && str[i] <= 'Z')
            res = res * 62 + str[i] - 'A' + 26;
        else if('0' <= str[i] && str[i] <= '9')
            res = res * 62 + str[i] - '0' + 52;
    }
    return res;
}
