#include<bits/stdc++.h>
using namespace std;

void heapSort(int[], int);
void buildHeap(int[], int);
void heapify(int[], int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        heapSort(arr, n);
        cout << endl;
    }
    return 0;
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void buildHeap(int arr[], int n){
    for(int i = (n / 2) - 1; i >= 0; i--){
        heapify(arr, i, n);
    }
}

void heapify(int arr[], int index, int n){
    int left = 2 * index + 1 < n ? 2 * index + 1 : -1;
    int right = 2 * index + 2 < n ? 2 * index + 2 : -1;
    int m = index;

    if(right != -1 && arr[left] < arr[right])
        m = right;
    else if(left != -1)
        m = left;
    if(arr[index] < arr[m]){
        swap(arr[index], arr[m]);
        heapify(arr, m, n);
    }
}
