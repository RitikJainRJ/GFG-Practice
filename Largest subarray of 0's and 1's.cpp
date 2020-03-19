int maxLen(int arr[], int n) {
    unordered_map<int, int> um;
    int curr = 0, result = 0;

    for(int i = 0; i < n; i++)
        if(arr[i] == 0)
            arr[i] = -1;
    for(int i = 0; i < n; i++){
        curr += arr[i];
        if(curr == 0)
            result = max(result, i + 1);
        if(um.find(curr) != um.end()){
            int temp = um[curr];
            result = max(result, i - temp);
        }
        if(um.find(curr) == um.end())
            um[curr] = i;
    }
    return result;
}
