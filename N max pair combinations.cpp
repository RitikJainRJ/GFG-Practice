#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::solve(vector<int> &A, vector<int> &B){
    multimap<int, pair<int, int>, greater<int>> om;
    set<pair<int, int>> os;
    vector<int> vec;
    int n = A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    om.insert({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    os.insert({n - 1, n - 1});
    while(n--){
        vec.push_back(om.begin()->first);
        int i = om.begin()->second.first;
        int j = om.begin()->second.second;
        if(os.find({i - 1, j}) == os.end()){
            om.insert({A[i - 1] + B[j], {i - 1, j}});
            os.insert({i - 1, j});
        }
        if(os.find({i, j - 1}) == os.end()){
            om.insert({A[i] + B[j - 1], {i, j - 1}});
            os.insert({i, j - 1});
        }
        om.erase(om.begin());
    }
    return vec;
}
