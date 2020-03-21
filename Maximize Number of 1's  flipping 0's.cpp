#include<bits/stdc++.h>
using namespace std;

int maxOnes(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << maxOnes(n) << endl;
	}
	return 0;
}

int maxOnes(int n){
    int arr[n], m, result = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;
    int i = 0, j, curr = 0;
    for(j = 0; j < n; j++){
        if(arr[j] == 0)
            curr++;
        if(curr <= m)
            result = max(result, j - i + 1);
        else{
            while(arr[i] != 0)
                i++;
            i++;
            curr--;
            result = max(result, j - i + 1);
        }
    }
    return result;
}
