void construct(int node, int s, int e, int *arr, int *tree){
    if(s == e){
        tree[node] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    construct(node * 2, s, mid, arr, tree);
    construct(node * 2 + 1, mid + 1, e, arr, tree);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int* constructST(int arr[],int n){
    int *tree;
    int t = 2 * pow(2, ceil(log2(n)));
    tree = new int[t];
    construct(1, 0, n - 1, arr, tree);
    return tree;
}

int _rmq(int node, int qs, int qe, int ss, int se, int *tree){
    if(qe < ss || se < qs)
        return INT_MAX;
    if(qs <= ss && se <= qe)
        return tree[node];
    int mid = (ss + se) / 2;
    return min(_rmq(node * 2, qs, qe, ss, mid, tree), _rmq(node * 2 + 1, qs, qe, mid + 1, se, tree));
}

int RMQ(int st[] , int n, int a, int b){
    return _rmq(1, a, b, 0, n - 1, st);
}
