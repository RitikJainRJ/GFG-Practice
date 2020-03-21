int Solution::solve(vector<int> &A, int B){
    int l, r, n = A.size(), ans;

    sort(A.begin(), A.end());
    r = A[n - 1] - A[0];
    l = 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        int temp = A[0], k = 1;

        for(int i = 1; i < n; i++){
            if(A[i] - temp >= mid){
                k++;
                temp = A[i];
            }
        }
        if(k < B)
            r = mid - 1;
        else{
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

