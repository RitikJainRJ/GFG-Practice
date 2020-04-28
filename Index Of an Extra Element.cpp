int findExtra(int a[], int b[], int n) {
    int i = 0, j = n - 1;

    while(i <= j){
        int m = (i + j) / 2;
        if(m == n)
            return m;
        else if(a[m] == b[m])
            i = m + 1;
        else if(a[m] != b[m])
            j = m - 1;
    }
    return i;
}
