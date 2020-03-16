#include<bits/stdc++.h>
using namespace std;

void merge(int, int);

int main(){
	int t, x, y;

	cin >> t;
	while(t--){
	    cin >> x >> y;
	    merge(x, y);
	    cout << endl;
	}
	return 0;
}

void merge(int m, int n){
    int arr1[m], arr2[n];

    for(int i = 0; i < m; i++)
        cin >> arr1[i];
    for(int i = 0; i < n; i++)
        cin >> arr2[i];
    for(int i = n - 1; i >= 0; i--){
        int j, last = arr1[m - 1];

        for(j = m - 2; arr1[j] > arr2[i] && j >= 0; j--)
            arr1[j + 1] = arr1[j];
        if(last > arr2[i] || j != m - 2){
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
    for(int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    for(int i = 0; i < n; i++)
        cout << arr2[i] << " ";
}
