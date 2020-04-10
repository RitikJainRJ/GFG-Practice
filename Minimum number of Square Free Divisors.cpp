#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int minDiv(int, vector<int>&);

int main(){
    int t, n;
    bool sieve[MAX + 1];
    vector<int> vec;

    memset(sieve, true, sizeof(sieve));
    for(int i = 2; i * i <= MAX; i++)
        if(sieve[i] == true){
            for(int j = i * i; j <= MAX; j = j + i)
                sieve[j] = false;
            vec.push_back(i);
        }
    cin >> t;
    while(t--){
        cin >> n;
        cout << minDiv(n, vec) << endl;
    }
    return 0;
}

int minDiv(int n, vector<int> &vec){
    int res = 0;

    for(int i = 0; i < vec.size() && vec[i] * vec[i] <= n; i++){
        if(n % vec[i] == 0){
            int t = 0;
            while(n % vec[i] == 0){
                t++;
                n = n / vec[i];
            }
            res = max(res, t);
        }
    }
    if(res == 0)
        return 1;
    return res;
}
