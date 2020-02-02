#include<bits/stdc++.h>
using namespace std;

int Solution::nchoc(int A, vector<int> &B){
    priority_queue<int> pq;
    int res = 0;

    for(int i = 0; i < B.size(); i++)
        pq.push(B[i]);
    while(A--){
        int temp = pq.top();
        res += temp;
        pq.pop();
        pq.push(temp / 2);
    }
    return res;
}
