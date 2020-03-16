#include<bits/stdc++.h>
using namespace std;

int findMissing(int);
int _findMissing(int[], int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << findMissing(n) << endl;
	}
	return 0;
}

int findMissing(int n){
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0, j = n - 1;
    while(i <= j){
        if(arr[i] <= 0)
            i++;
        else if(arr[j] > 0)
            j--;
        else{
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    /*for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << i << " " << j << endl;*/
    if(i == n)
        return 1;
    return _findMissing(arr + i, n - i);
}

int _findMissing(int arr[], int n){

    for(int i = 0; i < n; i++){
        int temp = abs(arr[i]) - 1;
        if(temp < n)
            arr[temp] = abs(arr[temp]) * -1;
    }
    for(int i = 0; i < n; i++){
        if(arr[i] > 0)
            return i + 1;
    }
    return n + 1;
}

