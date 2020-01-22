#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b;

    cin >> t;
    while(t--){
        cin >> a >> b;
        int temp = a | b;
        int temp2 = ~a | ~b;
        int res = temp & temp2;
        cout << res << endl;
    }
    return 0;
}
