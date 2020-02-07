int *mergeKArrays(int arr[][N], int k) {
    priority_queue<int, vector<int>, greater<int>> *pqarr;
    int *res = new int[k * k];

    pqarr = new priority_queue<int, vector<int>, greater<int>>[k];
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            pqarr[i].push(arr[i][j]);
    for(int i = 0; i < k * k; i++){
        int min = INT_MAX;
        int index;
        for(int j = 0; j < k; j++){
            if(!pqarr[j].empty() && min > pqarr[j].top()){
                min = pqarr[j].top();
                index = j;
            }
        }
        res[i] = min;
        pqarr[index].pop();
    }
    return res;
}
