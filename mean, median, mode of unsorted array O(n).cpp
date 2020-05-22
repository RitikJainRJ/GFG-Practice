#include<bits/stdc++.h>
using namespace std;

void findAll(vector<int>&);
int _partition(vector<int>&, int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n);

        for(int i = 0; i < n; i++)
            cin >> nums[i];
        findAll(nums);
        cout << endl;
    }
    return 0;
}

void findAll(vector<int> &nums){
    int n = nums.size(), sum = 0, m = 0, k;
    float mean, median, mode;
    unordered_map<int, int> um;

    for(int i = 0; i < n; i++){
        sum += nums[i];
        um[nums[i]]++;
        if(um[nums[i]] > m){
            m = um[nums[i]];
            mode = nums[i];
        }
    }
    mean = float(sum) / n;
    k = n / 2;
    int l = 0, r = n - 1;
    while(l <= r){
        int p = _partition(nums, l, r);
        if(p == k)
            break;
        else if(p < k)
            l = p + 1;
        else
            r = p - 1;
    }
    if(n % 2 != 0)
        median = nums[k];
    else{
        m = 0;
        for(int i = 0; i < k; i++)
            m = max(m, nums[i]);
        median = (m + nums[k]) * 0.5;
    }
    cout << mean << " " << median << " " << mode;
}

int _partition(vector<int> &nums, int l, int r){
    int i, j, p;

    i = l - 1;
    p = nums[r];
    for(j = l; j <= r; j++){
        if(nums[j] <= p){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    return i;
}
