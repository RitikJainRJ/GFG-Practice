/*
1
4 3
9 1 6 1
1 1
1 2
1 3

1
6 7
3 2 5 6 2 6
1 2
1 5
2 6
6 6
5 5
5 5
3 5

*/
#include<bits/stdc++.h>
using namespace std;

int solve(int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}

int solve(int n, int k){
    int arr[n], freq[n] = {0};
    pair<int, int> subarr[k];
    multimap<int, int, greater<int>> om;
    priority_queue<int> pq;
    int alice = 0, bob = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pq.push(arr[i]);
    }
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        subarr[i] = {a, b};
    }

    // here we can use prefix sum to find sum of sub-array O(n)
    for(int i = 0; i < k; i++)
        for(int j = subarr[i].first; j <= subarr[i].second; j++)
            alice += arr[j];

    // here we can use lazy sum to count the frequency in O(n)
    for(int i = 0; i < k; i++)
        for(int j = subarr[i].first; j <= subarr[i].second; j++)
            freq[j]++;
    for(int i = 0; i < n; i++)
        om.insert({freq[i], i});
    for(auto it = om.begin(); it != om.end(); it++){
        int temp = pq.top();
        pq.pop();
        arr[it->second] = temp;
    }
    for(int i = 0; i < k; i++)
        for(int j = subarr[i].first; j <= subarr[i].second; j++)
            bob += arr[j];
    return bob - alice;
}
