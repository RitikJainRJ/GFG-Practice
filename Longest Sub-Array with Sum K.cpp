#include<bits/stdc++.h>
using namespace std;

int longestSubarray(int, int);

int main(){
	int t, n, k;

	cin >> t;
	while(t--){
        cin >> n >> k;
        cout << longestSubarray(n, k) << endl;
	}
	return 0;
}

int longestSubarray(int n, int k){
    int arr[n], curr_sum = 0, max = 0;
    unordered_multimap<int, int> um;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        um.insert({curr_sum, i});
        if(curr_sum == k){
            int temp = i + 1;
            if(max < temp)
                max = temp;
        }
        auto itr = um.equal_range(curr_sum - k);
        for(auto it = itr.first; it != itr.second; it++){
            int temp = i - it->second;
            if(max < temp)
                max = temp;
        }
    }
    return max;
}
