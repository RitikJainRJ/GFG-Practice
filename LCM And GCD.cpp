#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

void solve(ll, ll);
ll GCD(ll, ll);

int main(){
    ll t, a, b;

    cin >> t;
    while(t--){
        cin >> a >> b;
        solve(a, b);
        cout << endl;
    }
    return 0;
}

ll GCD(ll a, ll b){
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

void solve(ll a, ll b){
    ll gcd = GCD(a, b);
    ll lcm = (a * b) / gcd;
    cout << lcm << " " << gcd;
}
