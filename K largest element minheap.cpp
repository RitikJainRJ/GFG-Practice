#include<bits/stdc++.h>
using namespace std;

void kLargest(int, int);

int main(){
	int t, n, k;

	cin >> t;
	while(t--){
	    cin >> n >> k;
	    kLargest(n, k);
	    cout << endl;
	}
	return 0;
}

void kLargest(int n, int k){
    int arr[n];
    priority_queue<int, vector<int>, greater<int>> minHeap;
    stack<int> s;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < k; i++)
        minHeap.push(arr[i]);
    for(int i = k; i < n; i++){
        if(minHeap.top() < arr[i]){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    while(!minHeap.empty()){
        s.push(minHeap.top());
        minHeap.pop();
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
