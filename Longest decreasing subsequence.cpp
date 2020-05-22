#include<bits/stdc++.h>
using namespace std;

int lds(vector<int>&);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n);

        for(int i = 0; i < n; i++)
            cin >> nums[i];
        cout << lds(nums) << endl;
    }
    return 0;
}

int lds(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 1);

    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(nums[j] > nums[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
    return *max_element(dp.begin(), dp.end());
}
