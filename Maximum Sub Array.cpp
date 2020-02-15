#include<bits/stdc++.h>
using namespace std;

void maxSubarray(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        maxSubarray(n);
        cout << endl;
    }
    return 0;
}

void maxSubarray(int n){
    int arr[n], curr_sum = 0, max = INT_MIN;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0, s, e;
    for(int j = 0; j < n; j++){
        if(arr[j] >= 0){
            curr_sum += arr[j];
        }
        else{
            if(max < curr_sum){
                max = curr_sum;
                s = i;
                e = j - 1;
            }
            else if(max == curr_sum){
                int a = e - s;
                int b = j - i;
                if(a < b){
                    s = i;
                    e = j - 1;
                }
            }
            i = j + 1;
            curr_sum = 0;
        }
    }
    if(max < curr_sum){
        s = i;
        e = n - 1;
    }
    for(int k = s; k <= e; k++)
        cout << arr[k] << " ";
}
