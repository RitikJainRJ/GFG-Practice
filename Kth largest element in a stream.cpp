#include<bits/stdc++.h>
using namespace std;

void klargest(int, int);

int main(){
    int t, k, n;

    cin >> t;
    while(t--){
        cin >> k >> n;
        klargest(n, k);
        cout << endl;
    }
    return 0;
}

void klargest(int n, int k){
    int arr[n];
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(pq.size() < k){
            pq.push(arr[i]);
            if(pq.size() == k)
                cout << pq.top() << " ";
            else
                cout << "-1" << " ";
        }
        else{
            if(arr[i] < pq.top())
                cout << pq.top() << " ";
            else{
                pq.pop();
                pq.push(arr[i]);
                cout << pq.top() << " ";
            }
        }
    }
}
