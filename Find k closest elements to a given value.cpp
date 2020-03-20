#include<bits/stdc++.h>
using namespace std;

void kClosest(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    kClosest(n);
	    cout << endl;
	}
	return 0;
}

void kClosest(int n){
    int arr[n], k, x;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k >> x;
    int i = 0, j = n - 1, m, p1, p2;
    while(i <= j){
        m = (i + j) / 2;
        if(arr[m] == x)
            break;
        else if(arr[m] > x)
            j = m - 1;
        else if(arr[m] < x)
            i = m + 1;
    }
    if(i > j){
        p1 = i;
        p2 = j;
    }
    else{
        p1 = m + 1;
        p2 = m - 1;
    }
    while(k--){
        int dif1 = INT_MAX, dif2 = INT_MAX;
        if(p1 < n)
            dif1 = abs(arr[p1] - x);
        if(p2 >= 0)
            dif2 = abs(arr[p2] - x);
        if(p1 < n && dif1 < dif2){
            cout << arr[p1] << " ";
            p1++;
        }
        else if(p2 >= 0){
            cout << arr[p2] << " ";
            p2--;
        }
    }
}
