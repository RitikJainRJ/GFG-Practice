#include<bits/stdc++.h>
#define ll unsigned long long
#define MAX 1000000007
using namespace std;

int Solution::nchoc(int A, vector<int> &B){
    priority_queue<ll> pq;
    ll res = 0;

    for(ll i = 0; i < B.size(); i++)
        pq.push(B[i]);
    while(A--){
        ll temp = pq.top();
        res = (res + temp) % MAX ;
        pq.pop();
        pq.push(temp / 2);
    }
    return res;
}
