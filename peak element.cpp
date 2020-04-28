int peakElement(int arr[], int n){
    int i = 0, j = n - 1;

    while(i < j){
        int m = (i + j) / 2, l  = 0, r = 0;

        if(m - 1 < 0)
            l = -1;
        if(m + 1 >= n)
            r = -1;
        if(l != -1 && r != -1){
            if(arr[m - 1] <= arr[m] && arr[m] >= arr[m + 1])
                return m;
            else if(arr[m - 1] <= arr[m] || arr[m] <= arr[m + 1])
                i = m + 1;
            else if(arr[m - 1] >= arr[m] || arr[m] >= arr[m + 1])
                j = m - 1;
        }
        else if(l != -1){
            if(arr[m - 1] <= arr[m])
                return m;
            else
                j = m - 1;
        }
        else if(r != -1){
            if(arr[m] >= arr[m + 1])
                return m;
            else
                i = m + 1;
        }
        else
            return m;
    }
    return i;
}
